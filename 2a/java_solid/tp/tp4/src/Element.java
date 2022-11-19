import java.io.Serializable;
import java.time.LocalDateTime;

public class Element implements Serializable {
    String filename;
    int size;
    int rights;
    LocalDateTime creationDate = LocalDateTime.now();

    Element(String filename, int rights){
        this.filename = filename;
        this.rights = rights;
    }

    Element(String filename){
        this.filename = filename;
    }
}
