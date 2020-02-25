       precision mediump float;
        
        uniform vec2 resolution;
        uniform vec2 mouse;
        uniform highp float time;
        
    
        float square(vec2 pos, float size) {
 
        	vec2 normCoords = gl_FragCoord.xy/resolution;
        
            float aspect = resolution.x/resolution.y;
            size*=0.1;
            if (length((normCoords.x-pos.x) * aspect)< size && length(normCoords.y-pos.y) < size) {
    
                return 1.0;
            
            } else {
                
                return 0.;
            }
        }
    
        float line(vec2 pos, float funct) {

           return step(funct,pos.y)-step(funct,pos.y-0.01);
        }
        
        float circle(vec2 pos, float size) {
            
            size = 1./size;
            size*=10.;
            float aspect = resolution.x/resolution.y;
            
            vec2 normCoord = vec2(gl_FragCoord.x/(resolution.x) * aspect,gl_FragCoord.y/resolution.y);
            
            float colour = distance(normCoord,pos); //circle-colour
            return smoothstep(colour / size, colour * size+0.02,1.); // '/'will smooth and '*' will sharp 
        }
        
        void main(){
            
        	//vec2 pos = gl_FragCoord.xy/resolution;
            
            //its pos and the variation of size
            float rect = square(vec2(0.35,0.5),abs(sin(time+time)));
            
            float rect2 = square(vec2(0.15,abs(cos(time))),abs(sin(time+time)));
            
            float circleOne = circle(vec2(abs(sin(time)),0.5),abs(cos(time+time)));
            
            vec3 squareOne = vec3(abs(cos(time)),abs(sin(time)),0.25) * rect;
            
            vec3 squareTwo = vec3(abs(cos(time)),0.1,0.15) * rect2;
            
            vec2 p = ( gl_FragCoord.xy / resolution.xy) -0.5 ;//online
	p.x *= resolution.x / resolution.y;//online

//online
	float c  = 0.0;
	float d = 1.0- smoothstep(0.1,0.15,0.5-length(p));
	float e = abs(sin(time+time))- smoothstep(0.1,0.55,0.1-length(p-vec2(0.25*sin(time),0.20*cos(time))));
	
    //online
	float moon = 2.- smoothstep(0.1,0.55,0.5-length(p-vec2(0.75*sin(time),0.75*cos(time))));//the fade black spot
   
	 
	c = (mod( gl_FragCoord.x ,2.0 )-mod( gl_FragCoord.y ,2.0 ) /d/e/moon);//online
	
    //online
	vec3 f = mix(vec3(0.,mouse.x,0.),vec3(c/moon,c/e,mouse.y),0.98);
	
   
        	gl_FragColor = vec4(squareOne + squareTwo + circleOne+f,1.0);
        }
