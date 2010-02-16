#! /bin/sh

echo
echo "Generating ChangeLog..."

git2cl >|ChangeLog

echo
echo "Updating gnulib sources..."
echo

gnulib-tool --update

echo
echo "Running autoreconf..."
echo

autoreconf --verbose --install --force
