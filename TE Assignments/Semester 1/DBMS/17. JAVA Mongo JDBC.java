import com.mongodb.client.MongoDatabase;  

import java.util.Iterator; 
import org.bson.Document; 
import com.mongodb.MongoClient; 
import com.mongodb.MongoCredential;  

public class RetrievingAllDocuments { 
   
   public static void main( String args[] ) {  
      
      // Creating a Mongo client 
      MongoClient mongo = new MongoClient( "localhost" , 27017 ); 

      // Creating Credentials 
      MongoCredential credential;
      credential = MongoCredential.createCredential("sampleUser", "myDb", 
         "password".toCharArray()); 
      System.out.println("Connected to the database successfully");
       
      //Creating a collection 
      database.createCollection("sampleCollection"); 
      System.out.println("Collection created successfully");   
      
      // Accessing the database 
      MongoDatabase database = mongo.getDatabase("myDb");  
      
      //Inserting into Database
      Document document = new Document("title", "MongoDB") 
      .append("id", 1)
      .append("description", "database") 
      .append("likes", 100) 
      collection.insertOne(document); 
      System.out.println("Document inserted successfully"); 
     
      // Retrieving a collection 
      MongoCollection<Document> collection = database.getCollection("sampleCollection");
      System.out.println("Collection sampleCollection selected successfully"); 

      // Getting the iterable object 
      FindIterable<Document> iterDoc = collection.find(); 
      int i = 1; 

      // Getting the iterator 
      Iterator it = iterDoc.iterator(); 
    
      while (it.hasNext()) {  
         System.out.println(it.next());  
      i++; 
      }
      
      // Retrieving a collection 
      MongoCollection<Document> collection = database.getCollection("sampleCollection");
      System.out.println("Collection myCollection selected successfully");
 
      collection.updateOne(Filters.eq("id", 1), Updates.set("likes", 150));       
      System.out.println("Document update successfully...");  
      
      // Retrieving the documents after updation 
      // Getting the iterable object
      FindIterable<Document> iterDoc = collection.find(); 
      int i = 1; 

      // Getting the iterator 
      Iterator it = iterDoc.iterator(); 

      while (it.hasNext()) {  
         System.out.println(it.next());  
         i++; 
      }

      // Retrieving a collection
      MongoCollection<Document> collection = database.getCollection("sampleCollection");
      System.out.println("Collection sampleCollection selected successfully"); 

      // Deleting the documents 
      collection.deleteOne(Filters.eq("id", 1)); 
      System.out.println("Document deleted successfully...");  
      
      // Retrieving the documents after updation 
      // Getting the iterable object 
      FindIterable<Document> iterDoc = collection.find(); 
      int i = 1; 

      // Getting the iterator 
      Iterator it = iterDoc.iterator(); 

      while (it.hasNext()) {  
         System.out.println("Inserted Document: "+i);  
         System.out.println(it.next());  
         i++; 
      }
           
   } 
}


/*OUTPUT

Connected to the database successfully 
Collection created successfully

Document inserted successfully

Document{{
   _id = 5967745223993a32646baab8, 
   title = MongoDB, 
   id = 1, 
   description = database, 
   likes = 100, 
}}  

Document{{
   _id = 7452239959673a32646baab8, 
   title = RethinkDB, 
   id = 2, 
   description = database, 
   likes = 200, 
}}

Document update successfully... 
Document {{
   _id = 5967745223993a32646baab8, 
   title = MongoDB, 
   id = 1, 
   description = database, 
   likes = 150, 
}}

Connected to the database successfully 
Collection sampleCollection selected successfully 
Document deleted successfully...

*/
