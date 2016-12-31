# arduino-balance

 Balance Emulator - (c) 2016 Online LIMS, Ricardo Timmermann

    The 'Balance emulator' sent random weights around TARGEDREAD 
    with a tolerance of READERROR in %. Adjust this values to get 
    a desired weight.

    Example: emulate a balance to read around 2 gr

      #define TARGETREAD 200
      #define READERROR 5	

      You must sent to the Arduino Balance a "READ\n" to get data.
      Similar like a ral balance when you request a weight by pressing print.
	
      Weight 1.9998 gr
      Weight 2.0212 gr
      Weight 1.8950 gr
      Weight 2.1010 gr
      Weight 2.0018 gr
      ...


