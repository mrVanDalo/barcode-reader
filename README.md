# barcode reader

flake to handle barcode readers

## How to use

``` nix
nix build
sudo ./result/bin/barcode-reader /dev/input/by-id/usb-<your-barcode-scanner> | \
while read line
do
  echo "Yey I just scanned this '$line'"
done
```

