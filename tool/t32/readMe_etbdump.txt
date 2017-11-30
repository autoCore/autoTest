The first thing(IMPORTANT), connect target by t32(the script will enable etb buffer, this will let t32 known there are some data in the buffer).

When system is halt, please change t32(system.mode) to "prepare" status. and then run the etb_readout.cmm scripts,
It will save the etb data to etb.bin.

Open t32 simulator, and then use the import_to_sim.cmm to analyse the data.(Just need adjust file name for axf and the 
above etb.bin)
