/*!\file Blatt1_Doxygen.cpp
 * \brief A short example (only) for documentation with doxygen
 *
 * From eclipse execute the program doxygen by the following steps:
 * 1. Open source-file with doxygen-compatible comments (e.g. Blatt1_Doxygen.cpp) in the editor and click into the editor window.
 * 2. Run-> external tools -> "Doxygen für alle Projekte (aus Blatt1_Doxygen)"
 *    In case of other projects the file "Blatt1_Doxygen/doxy/Doxygen für alle Projekte (aus Blatt1_Doxygen).launch" is required
 *    and therefore project Blatt1_Doxygen must be opened as well.
 * 3a. HTML-output: Double-click doxy/html/index.html
 * 3b. LaTeX-output as pdf: Run-> external tools-> "Preview Document in sumatra PDF" opens external viewer SumatraPDF or
 *     Double-click doxy/latex/refman.pdf opens the internal viewer pdf4Eclipse
 *     This seems to work only, after doxy\latex\make.bat has been run once. Double-click on make.bat in this case.
 *
 * See also Z_Doxygen.pdf in StudIP and the Link https://www.stack.nl/~dimitri/doxygen/manual/docblocks.html
 * In doxygen there is a C++ notation (used in this lecture) and a Java notation.
 *
 * The first line starting with command file containing the file name is required for documenting e.g. global functions.
 * The second line starting with command brief contains the one-line-short-description, ending with a blank line.
 * The following lines contain the long version of the documentation.
 *
 * This program just contains a very simple class to demonstrate doxygen comments.
 * For member functions the documentation can be placed directly above the declaration (in the header file *.hpp)
 * of directly above the definition (in the source file *.cpp).
 *
 * The comments containing documentation in doxygen style are usually placed immediately in front of a declaration or definition
 * of classes, memberfunctions, membervariables etc., often the brief description in front of the declaration and the long documentation in front
 * of the definition. The documentation of all classes etc. could be collected at the front of a file, but in this case structural commands have to be used, see below.
 *
 * For documentation of global objects (functions, typedefs, enums, macros etc.) the file-command must also be used.
 * For documentation of members of a class that class must also be documented.
 *
 * Only for member functions and member variables the documentation may be located directly behind the respective member.
 * All other documentation is located immediately ahead of the entity, of in arbitrary position in combination with structural commands.
 *
 * Doxygen knows quite a few equivalent notations, but be aware of the subtle differences.
 *
 */
#include <iostream>    // Contains e.g. cout, cin

//!  A test class. This is a brief description, if length is only one line.
/*!
  A more elaborate class description.
 */
class QTstyle_Test
{
private:
	//! An enum.
	/*! More detailed enum description. */
	enum TEnum {
		TVal1, /*!< Enum value TVal1. */
		TVal2, /*!< Enum value TVal2. */
		TVal3  /*!< Enum value TVal3. */
	};
	//! Enum pointer.
	/*! Details. */
	TEnum *enumPtr;
	//! Enum variable.
	/*! Details. */
	TEnum enumVar;

public:
	//! A constructor.
	/*!
      A more elaborate description of the constructor.
	 */
	QTstyle_Test();
	//! A destructor.
	/*!
      A more elaborate description of the destructor.
	 */
	virtual ~QTstyle_Test();

	//! A normal member taking two arguments and returning an integer value.
	/*!
      \param a an integer argument.
      \param s a constant character pointer.
      \return The test results
      \sa QTstyle_Test(), ~QTstyle_Test(), testMeToo() and publicVar()
	 */
	int testMe(int a, const char *s);

	//! A pure virtual member.
	/*!
      \sa testMe()
      \param c1 the first argument.
      \param c2 the second argument.
	 */
	virtual void testMeToo(char c1,char c2) = 0;

	//! A public variable.
	/*!
      Details.
	 */
	int publicVar;

	//! A function variable.
	/*!
      Details.
	 */
	int (*handler)(int a,int b);
};

class AnotherTest{};

/*! \class Test
    \brief Short documentation of AnotherTest, located not directly in front of the class definition.

    This documentation is not located directly in front of the class definition. This is allowed, but the following
    structural commands have to be used as required, starting with a backslash symbol.

    struct to document a C-struct.
    union to document a union.
    enum to document an enumeration type.
    fn to document a function.
    var to document a variable or typedef or enum value.
    def to document a define.
    typedef to document a type definition.
    file to document a file.
    namespace to document a namespace.
    package to document a Java package.
    interface to document an IDL interface.

    see https://www.stack.nl/~dimitri/doxygen/manual/docblocks.html
*/

int main()
{
	int var1 = 0; //!< Short description of var1
	int var2 = 0; //!< Long description of var2
	              //!< using multiple lines
	              //!<
	int var3 = 0; /**< Long description of var3 */

	var3 = var1 + var2 + var3;  // If variables are not used, a warning is generated.
	                            // This comment is intended for the programmer, not for the documentation
	std::cout << "Doxygen-Demo beendet!" << std::endl;

	return 0;
}
