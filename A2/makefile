MyProg.exe		: 	MyProg.o transform.o sprites.o fuzzylogic.o algorithm.o graphics.o 
	g++ -O2 -std=c++11  -Wl,-s -o MyProg.exe MyProg.o transform.o sprites.o fuzzylogic.o algorithm.o graphics.o -l gdi32 -static-libgcc -static-libstdc++
			
MyProg.o		:	MyProg.cpp graphics.h nodes.h transform.h sprites.h fuzzylogic.h algorithm.h
	g++ -O2  -std=c++11  -c -fpermissive -fconserve-space  -Wno-write-strings MyProg.cpp
	
transform.o		:	 transform.cpp transform.h
	g++ -O2  -std=c++11  -c -fpermissive -fconserve-space  -Wno-write-strings transform.cpp	

sprites.o		:	 sprites.cpp sprites.h graphics.h transform.h
	g++ -O2  -std=c++11  -c -fpermissive -fconserve-space  -Wno-write-strings sprites.cpp	
	
fuzzylogic.o	:	 fuzzylogic.cpp fuzzylogic.h
	g++ -O2  -std=c++11  -c -fpermissive -fconserve-space  -Wno-write-strings fuzzylogic.cpp		
	
algorithm.o		:	 algorithm.cpp algorithm.h
	g++ -O2  -std=c++11  -c -fpermissive -fconserve-space  -Wno-write-strings algorithm.cpp		

graphics.o		:	 graphics.cpp graphics.h
	g++ -O2  -std=c++11  -c -fpermissive -fconserve-space -Wno-write-strings  graphics.cpp
	
clean:
	del *.o
	del *.exe
