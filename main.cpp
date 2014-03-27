#include <phpcpp.h>
#include <iostream>

/**
 *  tell the compiler that the get_module is a pure C function
 */

void helloWorld(Php::Parameters &params) {
    std::string name = params[0];
    std::cout << "Hello " << name << "!" << std::endl;

}

void swap(Php::Parameters &params) {
    Php::Value temp = params[0];
    params[0] = params[1];
    params[1] = temp;
}

void swapObject(Php::Parameters &params)
{
    Php::Value temp = params[0];
    params[0] = params[1];
    params[1] = temp;
}

extern "C" {

    /**
     *  Function that is called by PHP right after the PHP process
     *  has started, and that returns an address of an internal PHP
     *  strucure with all the details and features of your extension
     *
     *  @return void*   a pointer to an address that is understood by PHP
     */
    PHPCPP_EXPORT void *get_module() {
        // static(!) Php::Extension object that should stay in memory
        // for the entire duration of the process (that's why it's static)
        static Php::Extension extension("skeleton", "1.0");
        extension.add("helloWorld", helloWorld);
        extension.add("swap", swap,{
            Php::ByRef("a", Php::Type::Numeric),
            Php::ByRef("b", Php::Type::Numeric)
        });
        extension.add("swapObject", swap,{
            Php::ByRef("a", "sampleClass"),
            Php::ByRef("b", "sampleClass")
        });

        // @todo    add your own functions, classes, namespaces to the extension

        // return the extension
        return extension;
    }
}
