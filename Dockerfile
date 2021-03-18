FROM scratch
ADD chroot-pdftk /
CMD [ "/bin/pdftk" ]
