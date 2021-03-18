# pdftk-binary

This is a complete binary package of `pdftk` v2.02 built on Slackware v14.2, which includes all the dynamic link libraries it needs
to run, all contained in a `chroot` - kinda like a poor man's container - so it **should** be able to run on any Linux platform.
Although I've only tested it on Alpine v3.12.

When you run it, all the files you want `pdftk` to process *must* be first copied into the `chroot` directory.

I only use `pdftk` for merging an XML file of data fields into a PDF input form, so the wrapper script
I have provided (called `pdftk`) is cumtomised to doing *only* this, but changing it to do whatever you want should be easy.


# Install

The `install` script (run `sudo ./install`) will copy the `chroot` to `/usr/local/chroot-pdftk`,
so you can now run `pdftk` with

	sudo chroot /usr/local/chroot-pdftk /bin/pdftk

It will also compile & copy the binary `pdftk-wrap` into `/usr/local/bin` and grant it `chroot` permission.

My wrapper script, called `pdftk` is copied into `/usr/local/bin`. The only purpose of the shell wrapper is to copy
the files to be processed into the `chroot` `/tmp/` directory.

You could also `mount --bind` your existing `/tmp` directory as `/usr/local/chroot-pdftk/tmp`, then `pdftk` could
access any files in your `/tmp` directory. Whatever works for you.


# Permissions

You *must* have `root` priviledges to run the install, becuase this whole package relies on `chroot` which is a priviledged operation.

The binary wrapper `pdftk-wrap` is granted `chroot` permission during install, but you need `root` permission to grant permission!

The `chroot` directory also requires that `procfs` is mounted at `/usr/local/chroot-pdftk/proc`, so this is also done during the `install`.

However, once the install has been run, `pdftk-wrap` can be run by an ordinary user, and appears to operate just like `pdftk`.


# License

The `LICENSE` applies to my code only. For the License terms for `pdftk` and the Slackware binaries,
please refer to their respective websites

	http://www.slackware.com/

	https://www.pdflabs.com/tools/pdftk-the-pdf-toolkit/

	pdftk 2.02 a Handy Tool for Manipulating PDF Documents
	Copyright (c) 2003-13 Steward and Lee, LLC - Please Visit: www.pdftk.com
	This is free software; see the source code for copying conditions. There is
	NO warranty, not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

