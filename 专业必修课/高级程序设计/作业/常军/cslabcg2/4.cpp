#include <bits/stdc++.h>

struct Token
{
    std::string value;
    std::string type;
};

std::vector<Token> tokens;

int main()
{
    std::string line;
    std::string token;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    while (iss >> token)
    {
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            tokens.push_back({token, "symbol"});
        }
        else
        {
            tokens.push_back({token, "number"});
        }
    }

    for (auto token = tokens.begin(); token != tokens.end(); token++)
    {
        if (token->type == "symbol")
        {
            if ((token - 2)->type != "symbol" && (token - 1)->type != "symbol")
            {
                std::string new_token ;

                if (token->value == "+" || token->value == "-")
                {
                    if((token - 2)->value[0]=='('){
                        (token - 2)->value.erase((token - 2)->value.begin());
                        (token - 2)->value.pop_back();
                    }
                    if((token - 1)->value[0]=='(' && token->value == "+"){
                        (token - 1)->value.erase((token - 1)->value.begin());
                        (token - 1)->value.pop_back();
                    }
                    if(tokens.size()==3){
                    new_token = (token - 2)->value + token->value + (token - 1)->value ;
                    }else{
                        new_token = "(" + (token - 2)->value + token->value + (token - 1)->value + ")";
                    }
                }
                else
                {
                    if((token - 1)->value[0]!='(' && token->value == "/" && (token - 1)->type!="number"){
                        (token - 1)->value.insert((token - 1)->value.begin(), '(');
                        (token - 1)->value.push_back(')');
                    }
                    new_token = (token - 2)->value + token->value + (token - 1)->value ;
                }

                auto insert_token = tokens.insert(token + 1, {new_token, "expression"});
                token = tokens.erase(token - 2, token + 1);
            }
            else
            {
                continue;
            }
        }
    }

    for (auto i : tokens)
    {
        std::cout << i.value;
    }
}