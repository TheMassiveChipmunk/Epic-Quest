#ifndef _UTIL_TCC
#define _UTIL_TCC

//Log a message to the current LOG_MODE
template <typename T>
void Venom::logMessage (const std::string& Message ,
			const T& Value)
{    
    //The output
    if (Venom::LOG_MODE & Venom::FOUT)
    {
	std::ofstream Log (Venom::LOG_TXT.c_str () , std::ios::app);
	
	Log << Message << Value << std::endl; 

	Log.close ();
    }
    if (Venom::LOG_MODE & Venom::CERR)
    {	
        std::cerr << Message << Value << std::endl; 
    }
    else if (Venom::LOG_MODE & Venom::COUT)
    {	
	std::cout << Message << Value << std::endl; 
    }
}

//Overloading for just a message to the current LOG_TXT
template <typename T> 
void Venom::logMessage (const T& Value)
{
    //Use the previous template function
    Venom::logMessage <T> ("" , Value); 
}

//Convert any value to a string
template <typename T>
inline std::string& Venom::toString (const T& Value , 
				     std::string& Buffer)
{
    //Stream to insert to
    std::stringstream Stream;
    
    Stream << Value;
    Stream >> Buffer;

    return Buffer;
}

//Convert a string to any value
template <typename T>
inline auto Venom::toT (const std::string& Value ,
			T& Buffer) -> T
{
    //Stream to insert to
    std::stringstream Stream;
    
    Stream << Value;
    Stream >> Buffer;    
    
    return Buffer;
}

#endif
