#include <bits/stdc++.h>

int main(){
    std::vector<std::string> out;
    std::vector<std::string> input;
    std::string line1,line2;

    while(getline(std::cin,line1)){
        getline(std::cin,line2);
        input.push_back(line1);
        input.push_back(line2);
    }


    while(!input.empty()){
        line1 = input[0];
        line2 = input[1];
        input.erase(input.begin());
        input.erase(input.begin());
        std::istringstream iss1(line1);
        std::istringstream iss2(line2);
        int a,b;
        std::vector<int> output,input1,input2;
        while (iss1 >> a){
            input1.push_back(a);
        }
        while (iss2 >> b){
            input2.push_back(b);
        }

        

        std::sort(input1.begin(),input1.end());
        std::sort(input2.begin(),input2.end());

        /*for(int i =0; i < input1.size(); i++){
        std::cout << input1[i] << " ";
        }
        std::cout <<std::endl;

        for(int i =0; i < input2.size(); i++){
        std::cout << input2[i] << " ";
        }
        std::cout <<std::endl;*/


        output.insert(output.end(),input1.begin(),input1.end());
        output.insert(output.end(),input2.begin(),input2.end());

        std::sort(output.begin(),output.end());

        std::vector<int>::iterator iter = unique(output.begin(), output.end());//遍历查找重复项
	    output.erase(iter, output.end());//删除重复项

        std::string outstr;
        for(int i = 0; i < output.size(); i++){
            outstr += std::to_string(output[i]) + " ";
        }

        //std::cout << outstr;
        out.push_back(outstr);

    }

    for(int i = 0; i < out.size(); i++){
        std::cout << out[i] << std::endl;
    }

}