import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.time.LocalDateTime;
import java.util.Scanner;

public class Filee extends Element{
    String content;

    Filee(String filename, String content, int rights){
        super(filename, rights);
        this.write(content);
        setSize();
    }

    Filee(String filename, String content){
        super(filename);
        this.write(content);
        this.rights = 755;
        setSize();
    }

    // add new content to file content
    void write(String s){
        this.content = this.content + s;
        setSize();
    }

    // set file size from content length
    void setSize(){
        this.size = this.content.length();
    }

    // toString
    public String toString(){
        return "TextFile " + this.filename + " created with rights " + this.rights + " on " + this.creationDate;
    }
}