rm -f dist.zip
zip -j dist.zip stdlib/*.cm[ai] stdlib/*.cmo otherlibs/str/*.cm[ai] otherlibs/unix/*.cm[ai] otherlibs/systhreads/*.cm[ai]

# Add packages
zip -j dist.zip ../ocaml-pkgs/num/src/*.cm[ai]
