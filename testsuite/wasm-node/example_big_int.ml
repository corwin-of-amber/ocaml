
let _ =
    let n = Big_int.big_int_of_string "4378927483923" in
    let m = Big_int.big_int_of_string "69236109238" in

    Format.printf "%s\n%!" (Big_int.string_of_big_int (Big_int.mult_big_int n m))

