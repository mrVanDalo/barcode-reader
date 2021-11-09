{ stdenv, ... }:
stdenv.mkDerivation {
  name = "barcode-reader";
  src = ./.;
  buildPhase = ''
    gcc main.c -o barcode-reader
  '';
  installPhase = ''
    mkdir -p $out/bin
    cp barcode-reader $out/bin
  '';
}
