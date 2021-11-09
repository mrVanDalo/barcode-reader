{
  description = "barcode reader setup";
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
      in
      {
        packages.barcode-reader = pkgs.callPackage ./default.nix { };
        defaultPackage = pkgs.callPackage ./default.nix { };
        # nix develop
        devShell = pkgs.mkShell {
          buildInputs =
            [ pkgs.astyle pkgs.gcc pkgs.evtest ];
        };
      });
}
