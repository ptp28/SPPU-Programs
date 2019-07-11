import java.util.*;
 
public class LRU 
{  
   public static void main(String[] args) 
   {
   		Scanner s = new Scanner(System.in);
    	int numPages , recent = 0 , pageFault = 0 , pageHit = 0 , numFrames;
      double ratio;
    	System.out.print("Enter NUMBER OF PAGES : ");
      numPages = s.nextInt();
    	int pageString[] = new int[numPages];
    	System.out.print("Enter PAGE REFERENCE STRING : \n");
    	for(int i=0 ; i<numPages ; i++)
      {	
      	pageString[i]=s.nextInt();
      }
      
     	System.out.print("\nEnter NUMBER OF FRAMES : "); 
     	numFrames = s.nextInt();
     	int frames[] = new int[numFrames];
     	int counter[] = new int[numFrames];
     	
     	for(int i=0 ; i<numFrames ; i++)
     	{
      		frames[i] = 0; 
        	counter[i] = 0;
    	}
     
    	for(int i=0 ; i<numPages ; i++)
    	{
    			int flag = 0;
        	for(int j=0 ; j<numFrames ; j++)
        	{
         		if(frames[j] == pageString[i])
           	{	
           		flag=1;
            	counter[j] = recent++;
            	pageHit++;
           		break;
           	}
        	}
        	if(flag == 0)
        	{
         		for(int j=0 ; j<numFrames ; j++)
            {
            	if(frames[j] == 0)
              {
           	    	frames[j] = pageString[i];
                  counter[j] = recent++;
                  flag=1;
                  pageFault++;
                  break;
              }      
            }
        	}
        	if(flag == 0)
        	{
        		int positionReplace = leastRecent(counter,numFrames);
            frames[positionReplace] = pageString[i];
            counter[positionReplace] = recent++;
            pageFault++;
        	}
        	System.out.println();
        	System.out.print("FRAMES     : ");
      	for(int j=0 ; j<numFrames ; j++)
      	{
         	System.out.print(frames[j] + " ");       		
      	}
      	System.out.println();
      	System.out.print("LAST USED  : ");
      	for(int j=0 ; j<numFrames ; j++)
      	{
         	System.out.print(counter[j] + " ");
      	}
      	System.out.println();
       
    	}
      System.out.println("\n\nPAGE FAULT : "+pageFault);
      System.out.println("PAGE HIT : "+pageHit);
      ratio = (pageHit*100)/numPages;
      System.out.print("EFFICIENCY RATIO = " + pageHit + "/" + numPages + " = ");
      System.out.print(ratio + "\n");
    }
  
	public static int leastRecent(int counterArray[],int nFrames)
	{
   	int minimum = counterArray[0];
    	int pos = 0;
    	for(int i=0 ; i<nFrames ; i++) 
    	{ 
    		if(minimum > counterArray[i])
         	pos = i;
    	}
 		return pos;   
	}
}
     
    
