var curpage = 1;var sliding = false;var click = true;var left = document.getElementById("left");var right = document.getElementById("right");var pagePrefix = "slide";var pageShift = 500;var transitionPrefix = "circle";var svg = true;// function leftSlide() {//     if (click) {//         if (curpage == 1)//             curpage = 5;//         console.log("woek");//         sliding = true;//         curpage--;//         svg = true;//         click = false;//         for (k = 1; k <= 4; k++) {//             var a1 = document.getElementById(pagePrefix + k);//             a1.className += " tran";//         }//         setTimeout(()=>{//             move();//         }//         , 200);//         setTimeout(()=>{//             for (k = 1; k <= 4; k++) {//                 var a1 = document.getElementById(pagePrefix + k);//                 a1.classList.remove("tran");//             }//         }//         , 1400);//     }// }const numberOfSLides= 26;setInterval(rightSlide, 7000)function rightSlide() {	console.log("before sliding one image",curpage);	if (curpage == numberOfSLides)		curpage = 0;	sliding = true;	curpage++;	svg = false;	click = false;	for (let k = 1; k <= numberOfSLides; k++) {		console.log(document.getElementById(pagePrefix + k));		let a1 = document.getElementById(pagePrefix + k);		a1.classList.add("tran");	}	setTimeout(()=>{			move();		}		, 200);	setTimeout(()=>{			for (let k = 1; k <= numberOfSLides; k++) {				let a1 = document.getElementById(pagePrefix + k);				a1.classList.remove("tran");			}		}		, 1400);	console.log("after sliding one image",curpage);}function move() {	if (sliding) {		sliding = false;		if (svg) {			for (j = 1; j <= 9; j++) {				var c = document.getElementById(transitionPrefix + j);				c.classList.remove("steap");				c.setAttribute("class", transitionPrefix + j + " streak");			}		} else {			for (j = 10; j <= 18; j++) {				var c = document.getElementById(transitionPrefix + j);				c.classList.remove("steap");				c.setAttribute("class", transitionPrefix + j + " streak");			}		}		setTimeout(()=>{				for (let i = 1; i <= numberOfSLides; i++) {					if (i == curpage) {						let a = document.getElementById(pagePrefix + i);						a.classList.add("up1");					} else {						let b = document.getElementById(pagePrefix + i);						b.classList.remove("up1");					}				}				sliding = true;			}			, 600);		setTimeout(()=>{				click = true;			}			, 1700);		setTimeout(()=>{				if (svg) {					for (j = 1; j <= 9; j++) {						var c = document.getElementById(transitionPrefix + j);						c.classList.remove("streak");						c.setAttribute("class", transitionPrefix + j + " steap");					}				} else {					for (j = 10; j <= 18; j++) {						var c = document.getElementById(transitionPrefix + j);						c.classList.remove("streak");						c.setAttribute("class", transitionPrefix + j + " steap");					}					sliding = true;				}			}			, 850);		setTimeout(()=>{				click = true;			}			, 1700);	}}//for codepen header// setTimeout(() => {// 	rightSlide();// }, 500);