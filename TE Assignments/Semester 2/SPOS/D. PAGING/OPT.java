import java.util.*;
 
public class OPT 
{  
   public static void main(String[] args) 
   {
   	Scanner s = new Scanner(System.in);
    	int numPages , recent = 0 , pageFault = 0 , numFrames , i , j , l , k;
        
    	System.out.print("Enter NUMBER OF PAGES : ");
      numPages = s.nextInt();
    	int pages[] = new int[numPages];
    	System.out.print("Enter PAGE REFERENCE STRING : \n");
    	for(i=0 ; i<numPages ; i++)
      {	
      	pages[i]=s.nextInt();
      }
      
     	System.out.print("\nEnter NUMBER OF FRAMES : "); 
     	numFrames = s.nextInt();
     	int frames[] = new int[numFrames];
	   
	   for(i=0 ; i<numFrames ; i++)
	   {
	   	frames[i] = -1;
	   }
     	
     	for(i=0 ; i<numPages ; i++)
	   {
			int isPageAlreadyPresent = 0;
	         
	        	for(j=0 ; j<numFrames ; j++)
	        	{
	         	if(pages[i] == frames[j])
	            {
	            	isPageAlreadyPresent = 1;
	               break;
	            }
	         }

			int isFrameEmpty = 0;  
	      for(j=0 ; j<numFrames ; j++)
	      {
	      	if(frames[j] == -1)
	      	{
	      		isFrameEmpty = 1;
	         	break;
	         }
			}
			
			if(isFrameEmpty == 1 && isPageAlreadyPresent == 0)
	      {
				frames[j] = pages[i];
			}	   
	    	else if(isFrameEmpty == 0 && isPageAlreadyPresent == 0)
	      {
	         	pageFault++;
	            int temp[]=new int[numFrames];
	            
	            for(k=0;k<numFrames;k++)
	            {  
	            	temp[k]=-1;
	               for(l=i+1;l<numPages-1;l++)
	               {
	               	if(frames[k] == pages[l])
	                  {
	                		temp[k] = l;
	                     break;
	                  }
	               }
	                
	            }
	            
	            int pos = -1;
	        		int flag=0;
	        		for(l=0;l<numFrames;l++)
	        		{
	            	if(temp[l]==-1)
	              	{
	               	pos = l;
	                  flag=1;
	                  break;
	              	}
	        		}
	         
	        		if(flag==1)
	        		{
	        			frames[pos] = pages[i];
	        		}
	        		else
	        		{
	           
	          		int max = temp[0];
	          		pos = 0;
	           
	          		for(k=1;k<numFrames;k++)
	         	 	{
	              		if(max<temp[k])
	              		{
	                  	pos = k;
	                  	max=temp[k];     
	              		}
	          		}
	           
	          		frames[pos] = pages[i];
	        		}
	         	       
	    	}
	      
	     	for(j=0;j<numFrames;j++)
	      {
	    		System.out.print(frames[j]+" ");
	      }
	         
	     	System.out.println("");
	         
		} 
	     
	   System.out.println("Page Faults: "+pageFault);
	
	}
}
	             
	         
