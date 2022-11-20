<?php 
    $user_name = $_POST["user"];
    $namep = $_POST["namep"];
    $codeValue = "";
    $defaultCode="";
    if(isset($_POST["code_type"])){  
        if($_POST["code_type"] == 'c')
        {  
            @$codeValue=file_get_contents("scode/".$user_name."/".$namep."/main.c");
            if($codeValue != false )
                echo $codeValue; 
            else
            {
                /*$defaultCode=file_get_contents("default_codes/main.c");
                echo $defaultCode;*/
echo "#include<stdio.h>

int main(){
    printf(\"Bonjour $user_name !\\nAllez, c'est à vous ! Bon courage ! ^_^\");
    return 0;
}";
            }
            
        } 

        else if($_POST["code_type"] == 'cpp11')  
        {  
            @$codeValue=file_get_contents("scode/".$user_name."/".$namep."/main.cpp");
            if($codeValue != false )
                echo $codeValue; 
            else
            {
            /*$defaultCode=file_get_contents("default_codes/main.cpp");
            echo $defaultCode;*/
echo "#include<iostream>

using namespace std;

int main(){
    cout << \"Bonjour $user_name !\\nAllez, c'est à vous ! Bon courage ! ^_^\";
    return 0;
}";
            }
        }  

        else if($_POST["code_type"] == 'java')  
        {  
            @$codeValue=file_get_contents("scode/".$user_name."/".$namep."/Main.java");
            if($codeValue != false)
                echo $codeValue; 
            else
            {
                /*$defaultCode=file_get_contents("default_codes/main.java");
                echo $defaultCode;*/
echo "class Main {
    public static void main(String[] args) {
        System.out.println(\"Bonjour $user_name !\\nAllez, c'est à vous ! Bon courage ! ^_^\"); 
    }
}";
            }                 
        } 

        else if($_POST["code_type"] == 'python3.2')  
        {  
            @$codeValue=file_get_contents("scode/".$user_name."/".$namep."/main.py");
            if($codeValue != false)
                echo $codeValue; 
            else
            {
                /*$defaultCode=file_get_contents("default_codes/main.py");
                echo $defaultCode;*/
                echo "print(\"Bonjour $user_name !\\nAllez, c'est à vous ! Bon courage ! ^_^\")";
            }
           
        } 
 }  
 ?> 