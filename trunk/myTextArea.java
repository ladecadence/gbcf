import javax.swing.JTextArea;

public class myTextArea extends JTextArea {

    public myTextArea(int rows, int cols) {
        super(rows,cols);
    }

    public void append(String text) {
        super.append(text);
        this.setCaretPosition(this.getCaretPosition()+text.length());
    }
}
