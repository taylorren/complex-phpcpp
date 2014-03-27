#include <phpcpp.h>
#include <cmath>
#include <iostream>
#include <sstream>

/**
 *  Counter class that can be used for counting
 */
class Complex : public Php::Base {
private:
    double r = 0, i = 0;

public:

    /**
     *  C++ constructor and destructor
     */
    Complex() {
    }
    
    virtual ~Complex() {
    }
    
    Php::Value getReal()
    {
        return r;
    }
    
    Php::Value getImage()
    {
        return i;
    }

    void __construct(Php::Parameters &params) {
        if (params.size() == 2) {
            r = params[0];
            i = params[1];
        }
        else
        {
            r=0;
            i=0;
        }
            

    }
    
    Php::Value add(Php::Parameters &params)
    {
        Php::Value t=params[0];
        Complex *a=(Complex *)t.implementation();
        
        r+=(double)a->getReal();
        i+=(double)a->getImage();
        
        return this;
    }
    
    Php::Value __toString()
    {
        std::ostringstream os;
        
        os<<r;
        if(i>=0)
            os<<'+';
        
        os<<i<<'i';

        return os.str();
    }

    /**
     *  Method to retrieve the current value
     *  @return double
     */
    Php::Value mod() const {
        return (double)sqrt(r * r + i * i);
    }
};

/**
 *  Switch to C context to ensure that the get_module() function
 *  is callable by C programs (which the Zend engine is)
 */
extern "C" {

    /**
     *  Startup function that is called by the Zend engine 
     *  to retrieve all information about the extension
     *  @return void*
     */
    PHPCPP_EXPORT void *get_module() {
        // create static instance of the extension object
        static Php::Extension myExtension("complex", "1.0");

        Php::Namespace myNamespace("trComplex");
        
        // description of the class so that PHP knows which methods are accessible
        Php::Class<Complex> complex("Complex");

        // register the increment method, and specify its parameters
        complex.method("mod", &Complex::mod, {});
        complex.method("__construct", &Complex::__construct);
        //complex.method("getReal", &Complex::getReal);
        complex.method("add", &Complex::add, {
            Php::ByVal("op", "trComplex\\Complex", false, true)
        });
        
        myNamespace.add(std::move(complex));

        // add the class to the extension
        //myExtension.add(std::move(complex));
        myExtension.add(std::move(myNamespace));

        // return the extension
        return myExtension;
    }
}
