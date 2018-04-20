# Copy msys folder of older MinGW installation into the MinGW folder of the updated version (because the rm command is required).
# Otherwise the command "rm -f" would have to be be replaced by "-del" and all / in path variables to be changed into \ for the del command.

CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 -Wno-write-strings

# TARGETS is a target 
TARGETS =	

# a macro, adding another target to the first target
TARGETS += 01_HelloWorld\01_HelloWorld.exe
# a macro replacing  the second target by a source file and a compilation command 
01_HelloWorld\01_HelloWorld.exe:	01_HelloWorld\main.cpp
	$(CXX) -o $@ $?
	
TARGETS += 03_Headerfiles\03_Headerfiles.exe
03_Headerfiles\03_Headerfiles.exe:	03_Headerfiles\main.cpp 03_Headerfiles\ausgabe.cpp 03_Headerfiles\ausgabe.hpp
	$(CXX) -o $@ $?
	
TARGETS += 06_CallByValue\06_CallByValue.exe
06_CallByValue\06_CallByValue.exe:	06_CallByValue\main.cpp
	$(CXX) -o $@ $?		
	
TARGETS += 07_CallByReference\07_CallByReference.exe
07_CallByReference\07_CallByReference.exe:	07_CallByReference\main.cpp
	$(CXX) -o $@ $?	
	
TARGETS += 08_CallByPointer\08_CallByPointer.exe
08_CallByPointer\08_CallByPointer.exe:	08_CallByPointer\main.cpp
	$(CXX) -o $@ $?		
	
TARGETS += 09_ForIfWhileSwitch\09_ForIfWhileSwitch.exe
09_ForIfWhileSwitch\09_ForIfWhileSwitch.exe:	09_ForIfWhileSwitch\main.cpp
	$(CXX) -o $@ $?	
	
TARGETS += 10_DatentypenSizeof\10_DatentypenSizeof.exe
10_DatentypenSizeof\10_DatentypenSizeof.exe:	10_DatentypenSizeof\main.cpp
	$(CXX) -o $@ $?	
	
TARGETS += 11_UnsignedSigned\11_UnsignedSigned.exe
11_UnsignedSigned\11_UnsignedSigned.exe:	11_UnsignedSigned\main.cpp
	$(CXX) -o $@ $?
	
TARGETS += 12_ClassCAuto\12_ClassCAuto.exe
12_ClassCAuto\12_ClassCAuto.exe:	12_ClassCAuto\main.cpp 12_ClassCAuto\cauto.cpp 12_ClassCAuto\cauto.hpp
	$(CXX) -o $@ $?		
	
TARGETS += 14_Vererbung\14a_Mehrfachvererbung\14_Mehrfachvererbung.exe
14_Vererbung\14a_Mehrfachvererbung\14_Mehrfachvererbung.exe:	14_Vererbung\14a_Mehrfachvererbung\Mehrfachvererbung.cpp 14_Vererbung\14a_Mehrfachvererbung\Mehrfachvererbung.hpp
	$(CXX) -o $@ $?

TARGETS += 14_Vererbung\14b_VirtuelleBasisklasse\14_VirtuelleBasisklasse.exe
14_Vererbung\14b_VirtuelleBasisklasse\14_VirtuelleBasisklasse.exe:	14_Vererbung\14b_VirtuelleBasisklasse\VirtuelleBasisklasse.cpp 14_Vererbung\14b_VirtuelleBasisklasse\VirtuelleBasisklasse.hpp
	$(CXX) -o $@ $?		
	
TARGETS += 17_Exceptions\17_Exceptions_Bsp1.exe
17_Exceptions\17_Exceptions_Bsp1.exe:	17_Exceptions\Exceptions_Bsp1.cpp
	$(CXX) -o $@ $?
	
TARGETS += 17_Exceptions\17_Exceptions_Bsp2.exe
17_Exceptions\17_Exceptions_Bsp2.exe:	17_Exceptions\Exceptions_Bsp2.cpp
	$(CXX) -o $@ $?
	
TARGETS += 17_Exceptions\17_Exceptions_Bsp3.exe
17_Exceptions\17_Exceptions_Bsp3.exe:	17_Exceptions\Exceptions_Bsp3.cpp
	$(CXX) -o $@ $?		
	
TARGETS += 18_Zeitmessung\18_Zeitmessung.exe
18_Zeitmessung\18_Zeitmessung.exe:	18_Zeitmessung\Zeitmessung.cpp
	$(CXX) -o $@ $?		
	
TARGETS += 19_Dateien\19_Dateien.exe
19_Dateien\19_Dateien.exe:	19_Dateien\main.cpp
	$(CXX) -o $@ $?		
	
TARGETS += 19_Dateien\Bild_verkleinern\19_BildVerkleinern.exe
19_Dateien\Bild_verkleinern\19_BildVerkleinern.exe:	19_Dateien\Bild_verkleinern\main.cpp 19_Dateien\Bild_verkleinern\cimagefile.cpp 19_Dateien\Bild_verkleinern\cimage.cpp
	$(CXX) -o $@ $?						

# a rule "all" with dependencies ${TARGETS}
all:  ${TARGETS}

# a rule "clean" with no dependencies and commands indented by TAB (not by spaces)
# rm -f ${TARGETS} does not work, because rm is not provided by MinGW
clean:
	rm -f ${TARGETS}

