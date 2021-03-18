# pdftk-binary

This is a binary package of `pdftk`, built on Slackware v14.2, that includes all the dynamic link libraries it needs
to run, all contained in a `chroot` - kinda like a poor man's container

This means when you run it, all the files you want it to process *must* be first copied into the `chroot`
directory.

I only use `pdftk` for merging an XML file of data fields into a PDF input form, so the wrapper script
I have provided (called `pdftk`) is cumtomised to doing *only* this, but changing it to do whatever you want should be easy.


# Install

The `install` script (just run `sudo ./install`) will copy the `chroot` to `/usr/local/chroot-pdftk`, so run it with

	chroot /usr/local/chroot-pdftk /bin/pdftk

And my wrapper script, called `pdftk` is copied into `/usr/local/bin`

If you don't have `root` permission (to copy into `/usr/local/`), it should run fine as you from your home directory,
it will just need installing there and some tweaks to the wrapper.


# License

The `LICENSE` applies to my code only. For the License terms for `pdftk` and the Slackware binaries,
please refer to their respective websites

	https://www.pdflabs.com/tools/pdftk-the-pdf-toolkit/

	http://www.slackware.com/
