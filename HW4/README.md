Note: For the AddStatement(string m_variableName, string m_value) function I read in m_value as a string because it could represent another variableName or an integer. Within the execute function for AddStatement I check for this and process accordingly. 
-- This applies for the SUB , MULT & DIV type Statements also

In the skeleton code it was written so that variables to be used in writing the execute() functions received parameters such as variableName or value, but within the function used them as m_variableName and m_value where the 'm_' was added so signify internal use within that specific inheritance of the Statement class. For consistency and ease of reading and writing the code, I instead received the parameters as 'm_variableName' and 'm_value' and use variable names such as 'var' and 'val' internally when writing the execute() functions. 


For the case:

PRINT A
PRINTALL
.

My program will output:

0
A 0