
function val() {
    d = document.getElementById("codetype").value;
    
    if (d=="python3.2"){
        editor.getSession().setMode("ace/mode/python");
    }
    if (d=="c"){
        editor.getSession().setMode("ace/mode/c_cpp");
    }
    if(d=="cpp11"){
        editor.getSession().setMode("ace/mode/c_cpp"); 
    }
    if (d=="java"){
        editor.getSession().setMode("ace/mode/java");
        
    }
}

function getText(){
    var x = document.getElementsByClassName("ace_content");
    alert(x[0].value);
    return false;
}