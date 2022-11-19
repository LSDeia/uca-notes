import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;

public class Dump implements ICommand{

    // Serialize file into <filename>.srl
    static void perform(Filee f){
        try {
            FileOutputStream file = new FileOutputStream(f.filename + ".srl");
            ObjectOutputStream out = new ObjectOutputStream(file);
            out.writeObject(f);
            out.close();
            file.close();
        } catch (IOException e){
            System.out.println("Problem when writing to file!");
        }
    }

    // Serialize dir into <filename>.srl
    static void perform(Directoryy d){
        try {
            FileOutputStream file = new FileOutputStream(d.filename + ".srl");
            ObjectOutputStream out = new ObjectOutputStream(file);
            out.writeObject(d);
            out.close();
            file.close();
        } catch (IOException e){
            System.out.println("Problem when writing to file!");
        }
    }
}
