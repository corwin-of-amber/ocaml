rm -f base.zip
zip -j base.zip ocaml ocamlc stdlib/*.cm[ai] stdlib/*.cmo otherlibs/str/*.cm[ai] otherlibs/unix/*.cm[ai] otherlibs/systhreads/*.cm[ai]


rm -rf package 
mkdir -p package/bin
cp *.wasm byterun/ocamlrun.wasm package/bin/
cp package.json README.md package/
touch package/index.js
tar zcf ocaml-wasm-4.07.2.tar.gz package


rm -rf package
mkdir -p package
cp package.base.json package/package.json
cp README.md base.zip package/
touch package/index.js
tar zcf ocaml-wasm-4.07.2-base.tar.gz package
