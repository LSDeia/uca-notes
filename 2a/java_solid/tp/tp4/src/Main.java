import java.text.FieldPosition;

public class Main {
    public static void main(String[] args) {
        // Create Directories
        Directoryy d1 = new Directoryy("gros-dossier",766);
        Directoryy d2 = new Directoryy("petit-dossier");

        // Create Files
        Filee f1 = new Filee("haha.txt","ceci est un contenu\n",777);
        Filee f2 = new Filee("haha1.txt","chut\n");
        Filee f3 = new Filee("haha1.txt","chut\n");

        // Add files and directories in d1 directory
        d1.add(f1);
        d1.add(f2);
        d2.add(f3);
        d1.add(d2);

        // Perform commands on Elements
        Lsr.perform(d1);
        Lsr.perform(f1);
        Dump.perform(d1);
        Dump.perform(f1);
    }
}