{ stdenv, ... }:
stdenv.mkDerivation {
  name = "fnord-4.5";
  src = ./.;
  buildPhase = ''
    gcc main.c -o fnord
  '';
  installPhase = ''
    mkdir -p $out/bin
    cp fnord $out/bin
  '';
}
