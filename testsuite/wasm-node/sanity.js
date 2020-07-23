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

    core.wasmFs.fs.writeFileSync('/a.ml', 
        `print_int @@ 4 + 9;; print_newline ();;
         print_endline "I am sane.";;`)

    core.start('runtime/ocamlrun.wasm',
        ['ocamlrun', '/usr/local/lib/ocaml/ocaml', '/a.ml']);
}


main();
