#! /bin/sh

touch ChangeLog || exit 1

echo
echo "Updating gnulib sources..."
echo

gnulib-tool --update

echo
echo "Running autoreconf..."
echo

autoreconf --verbose --install --force
