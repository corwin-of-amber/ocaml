# OCaml + WASM

This is a port of the OCaml runtime to the WebAssembly platform.
The core distribution includes `ocamlrun` (compiled as `ocamlrun.wasm`), and stubs for the native libraries `str`, `unix`, and `threads`.
This allows running OCaml bytecode binaries in a WebAssembly container, including in a browser.
They were built using [wasi-sdk](https://github.com/WebAssembly/wasi-sdk), and depend on [Wasmer-JS](https://github.com/wasmerio/wasmer-js) and [wasi-kernel](https://github.com/corwin-of-amber/wasi-kernel) for POSIX-like headers and runtime.

The current version is compatible with wasi-sdk 11 and wasi-kernel 0.1.1.

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
await core.proc.dyld.preload('dllcamlstr.so', 'dllcamlstr.wasm');
```

(This is using the low-level dynamic loader API; future versions of wasi-kernel may be able to read the dynamic library dependencies from the WASM binary itself.)


## Building from Source

**1** Configure a minimal OCaml with `clang`.
```
CC=clang ./configure  --disable-native-compiler --disable-ocamldoc --disable-debugger
```

**2** Build bytecode executables `ocaml` and `ocamlc`, as well as the standard library.
```
make world
```

**3** Copy preconfigured header files for WASM build (overwriting those generated by `configure`).
```
cp wasi-preconf/runtime/*.h runtime/caml/
```

**4** Build the runtime using [wasi-kernel](https://github.com/corwin-of-amber/wasi-kernel).
```
make -C runtime clean
wasi-kit make -C runtime ocamlrun
```

**5** (Optional) Build shared libraries `str`, `unix`, and `threads`.
```
./compile-shlibs
```

*Note:* The script invokes `clang` directly from wasi-sdk. It defaults to `/opt/wasi-sdk/bin/clang`.
If wasi-sdk is installed in a different location, update the `CC=` line in `compile-shlibs`.
