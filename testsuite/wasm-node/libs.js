const fs = require('fs'),
      unzip = require('jszip-unzip').default;

global.parcelRequire = undefined;  // bundle isolation :/

const { ExecCore } = require('wasi-kernel');


async function main() {
    var td = new TextDecoder('utf-8');

    var core = new ExecCore({tty: true});
    core.tty.on('data', x => console.log(td.decode(x)));

    await unzip(fs.readFileSync('base.zip'), {to:
        {directory: '/usr/local/lib/ocaml', fs: core.wasmFs.fs}});

    /* Test intrinsic `str`, `unix` and `threads` stubs */

    core.wasmFs.fs.writeFileSync('/a.ml', `
        #load "str.cma";;      print_endline "Loaded str (stubs).";;
        #load "unix.cma";;     print_endline "Loaded unix (stubs).";;
        #load "threads.cma";;  print_endline "Loaded threads (stubs).";;
    `)

    for (let p of preloads())
        await core.proc.dyld.preload(p.name, p.uri, p.reloc);
    
    await core.start('runtime/ocamlrun.wasm',
        ['ocamlrun', '/usr/local/lib/ocaml/ocaml', '/a.ml']);

    /* Test `num` */

    // Compile with:
    //   ocamlfind ocamlc -package num -linkpkg -o testsuite/wasm-node/example_big_int{.byte,.ml}
    core.wasmFs.fs.writeFileSync('/prog.bc',
        fs.readFileSync('testsuite/wasm-node/example_big_int.byte'));
    
    await core.start('runtime/ocamlrun.wasm',
        ['ocamlrun', '/prog.bc', '/a.ml']);
}


function preloads() {
    var locs = {'dllnums': '../ocaml-pkgs/num'};
    return ['dllcamlstr', 'dllunix', 'dllthreads', 'dllnums'].map(b => ({
        name: `${b}.so`, uri: `${locs[b] || '.'}/${b}.wasm`,
    }));
}

main();
