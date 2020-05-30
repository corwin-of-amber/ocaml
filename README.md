# OCaml + WASM

This is a port of the OCaml runtime to the WebAssembly platform.
The core distribution includes `ocamlrun` (compiled as `ocamlrun.wasm`), and stubs for the native libraries `str`, `unix`, and `threads`.
This allows running OCaml bytecode binaries in a WebAssembly container, including in a browser.
They were built using [wasi-sdk](https://github.com/WebAssembly/wasi-sdk), and depend on [Wasmer-JS](https://github.com/wasmerio/wasmer-js) and [wasi-kernel](https://github.com/corwin-of-amber/wasi-kernel) for runtime.

To run a compiled bytecode file, create a wasi-kernel `ExecCore` and pass the filename as an argument:
```js
import { ExecCore } from 'wasi-kernel';

var core = new ExecCore({tty: true}),
    td = new TextDecoder('utf-8');
core.tty.on('data', b => console.log(td.decode(b))); // to see the output
core.wasmFs.fs.writeFileSync('/my_program.bc', bytecode);
core.start('ocamlrun.wasm', ['ocamlrun', '/my_program.bc']);
```

Native libraries (`str`, `unix`, `threads`, and others that you may have compiled to WASM) need to be pre-loaded prior to invoking `start()`.
```js
await core.proc.dyld.preload('dllcamlstr.so', 'dllcamlstr.wasm', {
    data: ['caml_atom_table'], func: ['caml_alloc']
});
```

(This is using the low-level dynamic loader API, which requires spelling out the relocations; future versions of wasi-kernel may be able to read the relocation section from the WASM binary itself.)