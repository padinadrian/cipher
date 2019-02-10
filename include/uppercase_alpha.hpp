



namespace cipher
{
    /** Convert uppercase-alpha plaintext to generalized plaintext */
    void UpperAlphaToGeneralized(const std::string& plaintext, std::string& generalized)
    {
        generalized = plaintext;
        std::for_each(
            generalized.begin(),
            generalized.end(),
            [](char& c) { c -= 'A'; }
        );
    }
}



