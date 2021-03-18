# pdftk-binary

This is a complete binary package of `pdftk` v2.02 built on Slackware v14.2, which includes all the dynamic link libraries it needs
to run, all contained in a `chroot` - kinda like a poor man's container - so it **should** be able to run on any Linux platform.
Although I've only tested it on Alpine v3.12.

When you run it, copy all the files you want `pdftk` to process into `/usr/local/tmp`, but then their
path names must be given to `pdftk` as `/tmp/[your-file]`

e.g. `/usr/local/tmp/input.pdf` is specified to `pdftk` as `/tmp/input.pdf`

I only use `pdftk` for merging an XML file of data fields into a PDF input form, so that's the only
thing I have tested.

The `pdftk` wrapper provided will copy the files into `/usr/local/tmp` for you, but only works for the XML & form merge.


# Containter

If you prefer a proper docker container, its also there. I tested it with the form merge I use, but nothing else

Run `./dkmk` to make the container, copy your files into `/usr/local/tmp`, then run `./dkrun` with the `pdftk` parameters
you want, treating `/usr/local/tmp` as `/tmp`. That is `/usr/local/tmp/input.xml` is specified to `pdfktk` as `/tmp/input.xml`

	$ cp input.xml invoice.pdf /usr/local/tmp/
	$ ./dkrun /tmp/invoice.pdf fill_form /tmp/input.xml output - flatten > merged.pdf

By outputting to `stdout` I don't have to be concerned about getting the output file out again.


# Install

The `install` script (run `sudo ./install`) will copy the `chroot` to `/usr/local/chroot-pdftk`,
so you can now run `pdftk` with

	sudo chroot /usr/local/chroot-pdftk /bin/pdftk

It will also compile & copy the binary `pdftk-wrap` into `/usr/local/bin` and grant it `chroot` permission.

My wrapper script, called `pdftk` is copied into `/usr/local/bin`. The only purpose of the shell wrapper is to copy
the files to be processed into the `chroot` `/tmp/` directory.

The `install` script will also `mount --bind` `/usr/local/tmp` into `/usr/local/chroot-pdftk/tmp` so you can share files with the `chroot`
environment. The container uses the same directory.



# Permissions

You *must* have `root` priviledges to run the install, becuase the package relies on `chroot` which is a priviledged operation.

The binary wrapper `pdftk-wrap` is granted `chroot` permission during install, but you need `root` permission to grant permission!

The `chroot` directory also requires that `/proc` is mounted at `/usr/local/chroot-pdftk/proc`, so this is also done during the `install`.

However, once the install has been run, `pdftk-wrap` can be run by an ordinary user, and appears to operate just like `pdftk`.


# License

The `LICENSE` file in this repo applies to my code only. For the License terms for `pdftk` and the Slackware binaries,
please refer to their respective websites

	http://www.slackware.com/

	https://www.pdflabs.com/tools/pdftk-the-pdf-toolkit/

	pdftk 2.02 a Handy Tool for Manipulating PDF Documents
	Copyright (c) 2003-13 Steward and Lee, LLC - Please Visit: www.pdftk.com
	This is free software; see the source code for copying conditions. There is
	NO warranty, not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

