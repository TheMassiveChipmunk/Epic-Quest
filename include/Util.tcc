#ifndef _UTIL_TCC
#define _UTIL_TCC

/*
 * Log a message to the default error stream.
 * @param Message std::string That has the error message.
 * @param Value Value that caused the error.
 */
template <typename T>
void Venom::logMessage (const std::string& Message , const T& Value)
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

/*
 * Overload of logMessage for single messages.
 * @param Value The error message.
 */
template <typename T> 
void Venom::logMessage (const T& Value)
{
    //Use the previous template function
    Venom::logMessage <T> ("" , Value); 
}

/*
 * Convert any value to a string.
 * @param Value Value to be converted.
 * @param Buffer String to take in the new value.
 * @param return A reference to the buffer.
 */
template <typename T>
std::string& Venom::toString (const T& Value , std::string& Buffer)
{
    //Stream to insert to
    std::stringstream Stream;
    
    Stream << Value;
    Stream >> Buffer;

    return Buffer;
}

/*
 * Convert any string to any value.
 * @param Value String to be converted.
 * @param return Returns the buffer.
 */
template <typename T>
auto Venom::toT (const std::string& Value , T& Buffer) -> T
{
    //Stream to insert to
    std::stringstream Stream;
    
    Stream << Value;
    Stream >> Buffer;    
    
    return Buffer;
}

#endif
