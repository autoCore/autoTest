
Without JTAG, 2 ways of starting ctest at EVB board:
1.  Download aquila_evb_timer_test.bin to ddr address 0x00 then jump to 0x00,
    this way not write aquila_evb_timer_test.bin to emmc:
    Enter usb download mode by presseing up KP_UP when power on or reset,
    1)IN bootrom, run the command to download sdl.pak:
      aimgtool.exe cmd -c DWLD -m 1 -n spl -i sdl.pak
      or
      ./aimgtool cmd -c DWLD -m 1 -n spl -i sdl.pak
      note: replace sdl.pak with the right path
    2)In SDL , run the command:
      aimgtool.exe cmd -c DWLD -d 0x00 -m 1 -n cache -i ../../build/aquila_evb/img/timer/aquila_evb_timer_test.bin
     or
      ./aimgtool cmd -c DWLD -d 0x00 -m 1 -n cache -i ../../build/aquila_evb/img/timer/aquila_evb_timer_test.bin
      note: replace aquila_evb_timer_test.bin with the right ctest image path
      here -d 0x00 means Download aquila_evb_timer_test.bin to ddr address 0x00 then run from 0x00
           -m 1 means only download to ddr and run ,but not write emmc
           -n cache    use the cache patirion name,which not verify

2.  Write aquila_evb_timer_test.bin to sloader partition in emmc then reset from bootrom:
    1) use aquila_evb_timer_test.bin to generate sloader.img.sig
        a)suggest to  use android environment,
          copy aquila_evb_timer_test.bin to android OUT dir,rename to sloader.img,use cmd:
          sign-images
          to generate sloader.img.sig

        b)for those who no android environment,
          cp ../../build/aquila_evb/img/timer/aquila_evb_timer_test.bin sloader.img
          ./aimgtool signall -c testkeys/secureboot/rtpk.cfg -k testkeys/secureboot -i .

    2)Enter usb download mode by presseing up KP_UP when power on or reset,
         IN bootrom, run the command to write the sloader.img.sig to emmc and reboot:
         aimgtool.exe download -t ctest_table.cfg
         or
         ./aimgtool download -t ctest_table.cfg
         wait a moment then enter ctest environment

  Note: we can get the newest spl.pak./sdl.pak from daily build images in http://10.1.24.57/adroid7.1/

