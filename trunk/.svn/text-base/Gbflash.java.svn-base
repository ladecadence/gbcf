import java.io.*;
import java.util.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import org.jdesktop.swingworker.*;


public class Gbflash implements ActionListener
{
    static String version = "0.8";
    static int ram=1, rom=4;
    static boolean eraseBeforeWrite = true;
    static boolean checkSize = true;
    static JFrame frame;
    static JLabel label;
    static JScrollPane scroll;
    static myTextArea output;
    static JFileChooser fc;
    static JMenuBar mb;
    static JToolBar tb;
    static ResourceBundle labels;
    static ImageIcon statusIcon;
    static ImageIcon readRomIcon;
    static ImageIcon readRamIcon;
    static ImageIcon writeRomIcon;
    static ImageIcon writeRamIcon;
    static ImageIcon eraseRomIcon;
    static ImageIcon eraseRamIcon;
    static ImageIcon flasherIcon;
    static JLabel flasherLabel;
    static JButton statusButton;
    static JButton readRomButton;
    static JButton readRamButton;
    static JButton writeRomButton;
    static JButton writeRamButton;
    static JButton eraseRomButton;
    static JButton eraseRamButton;

    public JMenuBar createMenuBar() {

        JMenuBar myMenuBar;
        JMenu menuFile;
        JMenu menuOptions;
        JMenu menuHelp;

        JMenu menuRam;
        JMenu menuROM;

        JMenuItem menuStatus;
        JMenuItem menuReadROM;
        JMenuItem menuWriteROM;
        JMenuItem menuReadRam;
        JMenuItem menuWriteRam;
        JMenuItem menuEraseROM;
        JMenuItem menuEraseRam;
        JMenuItem menuQuit;

        JMenuItem menuAbout;

        JRadioButtonMenuItem rbMenuROM;
        JRadioButtonMenuItem rbMenuRam;

        JCheckBoxMenuItem cbMenuEBF;
        JCheckBoxMenuItem cbMenuCS;
        ResourceBundle labels;


        ResourceBundle lab =
            ResourceBundle.getBundle("Labels");


        /*******************************************/
        myMenuBar = new JMenuBar();
        myMenuBar.setOpaque(true);
        //myMenuBar.setBackground(new Color(154, 165, 127));
        myMenuBar.setPreferredSize(new Dimension(200, 20));

        /*******************************************/

        menuFile = new JMenu(lab.getString("FILE_TEXT"));
        menuFile.setMnemonic(KeyEvent.VK_F);
        menuFile.getAccessibleContext().setAccessibleDescription(
            "File operations");
        myMenuBar.add(menuFile);

        menuStatus = new JMenuItem(lab.getString("STATUS_TEXT"), KeyEvent.VK_S);
        menuStatus.setAccelerator(KeyStroke.getKeyStroke(
                                      KeyEvent.VK_S, ActionEvent.ALT_MASK));
        menuStatus.getAccessibleContext().setAccessibleDescription(
            "Query cartridge information");
        menuFile.add(menuStatus);

        menuFile.addSeparator();

        menuReadROM = new JMenuItem(lab.getString("READ_ROM_TEXT"), KeyEvent.VK_R);
        menuReadROM.setAccelerator(KeyStroke.getKeyStroke(
                                       KeyEvent.VK_R, ActionEvent.ALT_MASK));
        menuReadROM.getAccessibleContext().setAccessibleDescription(
            "Read cartridge ROM to file");
        menuFile.add(menuReadROM);

        menuWriteROM = new JMenuItem(lab.getString("WRITE_ROM_TEXT"), KeyEvent.VK_W);
        menuWriteROM.setAccelerator(KeyStroke.getKeyStroke(
                                        KeyEvent.VK_W, ActionEvent.ALT_MASK));
        menuWriteROM.getAccessibleContext().setAccessibleDescription(
            "Write cartridge ROM from file");
        menuFile.add(menuWriteROM);

        menuReadRam = new JMenuItem(lab.getString("READ_RAM_TEXT"), KeyEvent.VK_E);
        menuReadRam.setAccelerator(KeyStroke.getKeyStroke(
                                       KeyEvent.VK_E, ActionEvent.ALT_MASK));
        menuReadRam.getAccessibleContext().setAccessibleDescription(
            "Read cartridge RAM to file");
        menuFile.add(menuReadRam);

        menuWriteRam = new JMenuItem(lab.getString("WRITE_RAM_TEXT"), KeyEvent.VK_I);
        menuWriteRam.setAccelerator(KeyStroke.getKeyStroke(
                                        KeyEvent.VK_I, ActionEvent.ALT_MASK));
        menuWriteRam.getAccessibleContext().setAccessibleDescription(
            "Write Cartridge RAM from file");
        menuFile.add(menuWriteRam);

        menuEraseROM = new JMenuItem(lab.getString("ERASE_ROM_TEXT"), KeyEvent.VK_H);
        menuEraseROM.setAccelerator(KeyStroke.getKeyStroke(
                                        KeyEvent.VK_H, ActionEvent.ALT_MASK));
        menuEraseROM.getAccessibleContext().setAccessibleDescription(
            "Erase cartridge ROM");
        menuFile.add(menuEraseROM);

        menuEraseRam = new JMenuItem(lab.getString("ERASE_RAM_TEXT"), KeyEvent.VK_M);
        menuEraseRam.setAccelerator(KeyStroke.getKeyStroke(
                                        KeyEvent.VK_M, ActionEvent.ALT_MASK));
        menuEraseRam.getAccessibleContext().setAccessibleDescription(
            "Erase cartridge RAM");
        menuFile.add(menuEraseRam);


        menuFile.addSeparator();

        menuQuit = new JMenuItem(lab.getString("QUIT_TEXT"), KeyEvent.VK_Q);
        menuQuit.setAccelerator(KeyStroke.getKeyStroke(
                                    KeyEvent.VK_Q, ActionEvent.ALT_MASK));
        menuQuit.getAccessibleContext().setAccessibleDescription(
            "Exit application");
        menuFile.add(menuQuit);

        /*****************************************************/

        menuOptions = new JMenu(lab.getString("OPTIONS_TEXT"));
        menuOptions.setMnemonic(KeyEvent.VK_O);
        menuOptions.getAccessibleContext().setAccessibleDescription(
            "Memory Options");


        menuROM = new JMenu(lab.getString("ROM_TEXT"));
        menuRam = new JMenu(lab.getString("RAM_TEXT"));
        menuOptions.add(menuROM);
        menuOptions.add(menuRam);


        ButtonGroup group = new ButtonGroup();

        rbMenuROM = new JRadioButtonMenuItem("ROM: 32 KB");
        group.add(rbMenuROM);
        rbMenuROM.addActionListener(this);
        menuROM.add(rbMenuROM);

        rbMenuROM = new JRadioButtonMenuItem("ROM: 64 KB");
        group.add(rbMenuROM);
        rbMenuROM.addActionListener(this);
        menuROM.add(rbMenuROM);

        rbMenuROM = new JRadioButtonMenuItem("ROM: 128 KB");
        group.add(rbMenuROM);
        rbMenuROM.addActionListener(this);
        menuROM.add(rbMenuROM);

        rbMenuROM = new JRadioButtonMenuItem("ROM: 256 KB");
        group.add(rbMenuROM);
        rbMenuROM.addActionListener(this);
        menuROM.add(rbMenuROM);

        rbMenuROM = new JRadioButtonMenuItem("ROM: 512 KB");
        rbMenuROM.setSelected(true);
        group.add(rbMenuROM);
        rbMenuROM.addActionListener(this);
        menuROM.add(rbMenuROM);

        rbMenuROM = new JRadioButtonMenuItem("ROM: 1 MB");
        group.add(rbMenuROM);
        rbMenuROM.addActionListener(this);
        menuROM.add(rbMenuROM);

        rbMenuROM = new JRadioButtonMenuItem("ROM: 2 MB");
        group.add(rbMenuROM);
        rbMenuROM.addActionListener(this);
        menuROM.add(rbMenuROM);

        rbMenuROM = new JRadioButtonMenuItem("ROM: 4 MB");
        group.add(rbMenuROM);
        rbMenuROM.addActionListener(this);
        menuROM.add(rbMenuROM);

        rbMenuROM = new JRadioButtonMenuItem("ROM: 8 MB");
        group.add(rbMenuROM);
        rbMenuROM.addActionListener(this);
        menuROM.add(rbMenuROM);

        ButtonGroup groupRam = new ButtonGroup();

        rbMenuRam = new JRadioButtonMenuItem("RAM: 2 KB");
        groupRam.add(rbMenuRam);
        rbMenuRam.addActionListener(this);
        menuRam.add(rbMenuRam);

        rbMenuRam = new JRadioButtonMenuItem("RAM: 8 KB");
        rbMenuRam.setSelected(true);
        groupRam.add(rbMenuRam);
        rbMenuRam.addActionListener(this);
        menuRam.add(rbMenuRam);

        rbMenuRam = new JRadioButtonMenuItem("RAM: 32 KB");
        groupRam.add(rbMenuRam);
        rbMenuRam.addActionListener(this);
        menuRam.add(rbMenuRam);

        rbMenuRam = new JRadioButtonMenuItem("RAM: 128 KB");
        groupRam.add(rbMenuRam);
        rbMenuRam.addActionListener(this);
        menuRam.add(rbMenuRam);

        menuOptions.addSeparator();

        cbMenuEBF = new JCheckBoxMenuItem(lab.getString("EBW_TEXT"));
        cbMenuEBF.addActionListener(this);
        cbMenuEBF.setState(true);
        menuOptions.add(cbMenuEBF);

        cbMenuCS = new JCheckBoxMenuItem(lab.getString("CS_TEXT"));
        cbMenuCS.addActionListener(this);
        cbMenuCS.setState(true);
        menuOptions.add(cbMenuCS);

        myMenuBar.add(menuOptions);

        /*****************************************************/

        menuHelp = new JMenu(lab.getString("HELP_TEXT"));
        menuFile.setMnemonic(KeyEvent.VK_H);
        menuFile.getAccessibleContext().setAccessibleDescription(
            "Help");
        myMenuBar.add(menuHelp);

        menuAbout = new JMenuItem(lab.getString("ABOUT_TEXT"), KeyEvent.VK_B);
        menuAbout.setAccelerator(KeyStroke.getKeyStroke(
                                     KeyEvent.VK_B, ActionEvent.ALT_MASK));
        menuAbout.getAccessibleContext().setAccessibleDescription(
            "Exit application");
        menuHelp.add(menuAbout);

        /******************************************************/

        menuFile.addActionListener(this);
        menuStatus.addActionListener(this);
        menuReadROM.addActionListener(this);
        menuWriteROM.addActionListener(this);
        menuWriteRam.addActionListener(this);
        menuReadRam.addActionListener(this);
        menuEraseROM.addActionListener(this);
        menuEraseRam.addActionListener(this);


        menuQuit.addActionListener(this);

        menuOptions.addActionListener(this);
        menuHelp.addActionListener(this);
        menuROM.addActionListener(this);
        menuRam.addActionListener(this);

        menuAbout.addActionListener(this);

        return myMenuBar;
    }

    public static void createGUI() {

        Locale[] supportedLocales = {
            new Locale("es","ES"),
            new Locale("en","US")
        };

        // Translations
        labels =
            ResourceBundle.getBundle("Labels");

	statusIcon = new ImageIcon("images/status.png");
        readRomIcon = new ImageIcon("images/read-rom.png");
        readRamIcon = new ImageIcon("images/read-ram.png");
        writeRomIcon = new ImageIcon("images/write-rom.png");
        writeRamIcon = new ImageIcon("images/write-ram.png");
        eraseRomIcon = new ImageIcon("images/erase-rom.png");
        eraseRamIcon = new ImageIcon("images/erase-ram.png");
	
	flasherIcon = new ImageIcon("images/flasher.png");
	flasherLabel = new JLabel(flasherIcon);

        frame = new JFrame("Java GBFlasher");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        label = new JLabel(labels.getString("NO_ACT_TEXT"));

        output = new myTextArea(25,60);
	output.setBackground(Color.BLUE);
	output.setForeground(Color.WHITE);

        scroll = new JScrollPane(output);
        scroll.setHorizontalScrollBarPolicy(ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER);

        tb = new JToolBar("GBFlasher");
	statusButton = new JButton(labels.getString("STATUS_TEXT"), statusIcon);
	tb.add(statusButton);
        readRomButton = new JButton(labels.getString("READ_ROM_TEXT"), readRomIcon);
        tb.add(readRomButton);
        writeRomButton = new JButton(labels.getString("WRITE_ROM_TEXT"), writeRomIcon);
        tb.add(writeRomButton);
        eraseRomButton = new JButton(labels.getString("ERASE_ROM_TEXT"), eraseRomIcon);
        tb.add(eraseRomButton);
        readRamButton = new JButton(labels.getString("READ_RAM_TEXT"), readRamIcon);
        tb.add(readRamButton);
        writeRamButton = new JButton(labels.getString("WRITE_RAM_TEXT"), writeRamIcon);
        tb.add(writeRamButton);
        eraseRamButton = new JButton(labels.getString("ERASE_RAM_TEXT"), eraseRamIcon);
        tb.add(eraseRamButton);

        frame.getContentPane().add(tb, BorderLayout.PAGE_START);
        frame.getContentPane().add(scroll, BorderLayout.LINE_START);
	frame.getContentPane().add(flasherLabel, BorderLayout.LINE_END);
        frame.getContentPane().add(label, BorderLayout.PAGE_END);

        Gbflash gbflash = new Gbflash();
	
	statusButton.addActionListener(gbflash);
        readRomButton.addActionListener(gbflash);
        writeRomButton.addActionListener(gbflash);
        readRamButton.addActionListener(gbflash);
        writeRamButton.addActionListener(gbflash);
        eraseRomButton.addActionListener(gbflash);
        eraseRamButton.addActionListener(gbflash);

        mb = gbflash.createMenuBar();

        frame.setJMenuBar(mb);


        frame.pack();
        frame.setVisible(true);

        fc = new JFileChooser();
        fc.setMultiSelectionEnabled(false);


    }


    public void disableMenus() {

        MenuElement[] menuList = mb.getSubElements();

        for (int i=0; i<menuList.length; i++) {
            JMenuItem mi = (JMenuItem) menuList[i];
            mi.setEnabled(false);
        }
    }

    public void enableMenus() {

        MenuElement[] menuList = mb.getSubElements();

        for (int i=0; i<menuList.length; i++) {
            JMenuItem mi = (JMenuItem) menuList[i];
            mi.setEnabled(true);
        }
    }

    public void actionPerformed(ActionEvent e)
    {
        // Get information from the action event...

        if (e.getSource().getClass().getName() != "javax.swing.JButton") {

            final JMenuItem source = (JMenuItem)(e.getSource());


            if (source.getText() == labels.getString("QUIT_TEXT")) {
                System.exit(0);
            }

            if (source.getText() == labels.getString("STATUS_TEXT")) {

                // Background thread
                org.jdesktop.swingworker.SwingWorker<Object, Void> worker = 
		        new org.jdesktop.swingworker.SwingWorker<Object, Void>() {
                    public Object doInBackground() {
                        ExecCLI ex = new ExecCLI(labels.getString("STATUS_CMD"), "", 0, "");
                        return ex;
                    }
                    public void done() {
                        enableMenus();
                    }
                };

                worker.execute();

            }

            if (source.getText() == labels.getString("READ_ROM_TEXT")) {
                fc.setDialogTitle(labels.getString("SAVE_F_TO_TEXT"));
                fc.setFileFilter(new GBRomFilter());
                int returnVal = fc.showSaveDialog(output);

                if (returnVal == JFileChooser.APPROVE_OPTION) {
                    final File file = fc.getSelectedFile();


                    // Background thread
                    org.jdesktop.swingworker.SwingWorker<Object, Void> worker = new org.jdesktop.swingworker.SwingWorker<Object, Void>() {
                        public Object doInBackground() {
                            int vrom = rom;
                            if (checkSize) {
                                ExecCLI o =  new ExecCLI("--get-rom-size","",0,"");
                                vrom = o.retval-10;
                            }
                            return new ExecCLI(labels.getString("READ_ROM_CMD"), "--rom", vrom, file.getAbsolutePath());
                        }
                        public void done() {
                            enableMenus();
                        }
                    };

                    worker.execute();

                }
                else {
                    output.append("\n");
                    label.setText(labels.getString("CANCEL_TEXT"));
                }
            }

            if (source.getText() == labels.getString("WRITE_ROM_TEXT")) {
                fc.setDialogTitle(labels.getString("WRITE_F_FROM_TEXT"));
                fc.setFileFilter(new GBRomFilter());
                int returnVal = fc.showOpenDialog(output);

                if (returnVal == JFileChooser.APPROVE_OPTION) {
                    final File file = fc.getSelectedFile();

                    // Background thread
                    org.jdesktop.swingworker.SwingWorker<Object, Void> worker = new org.jdesktop.swingworker.SwingWorker<Object, Void>() {
                        public Object doInBackground() {
                            if (eraseBeforeWrite) {
                                Object o =  new ExecCLI(labels.getString("ERASE_ROM_CMD"), "--rom", rom, "");
                            }
                            return new ExecCLI(labels.getString("WRITE_ROM_CMD"), "--rom", rom, file.getAbsolutePath());
                        }
                        public void done() {
                            enableMenus();
                        }
                    };

                    worker.execute();

                }
                else {
                    output.append("\n");
                    label.setText(labels.getString("CANCEL_TEXT"));
                }
            }

            if (source.getText() == labels.getString("WRITE_RAM_TEXT")) {
                fc.setDialogTitle(labels.getString("WRITE_R_FROM_TEXT"));
                fc.setFileFilter(new GBSaveFilter());
                int returnVal = fc.showOpenDialog(output);

                if (returnVal == JFileChooser.APPROVE_OPTION) {
                    final File file = fc.getSelectedFile();

                    // Background thread
                    org.jdesktop.swingworker.SwingWorker<Object, Void> worker = new org.jdesktop.swingworker.SwingWorker<Object, Void>() {
                        public Object doInBackground() {
                            if (eraseBeforeWrite) {
                                Object o =  new ExecCLI(labels.getString("ERASE_RAM_CMD"), "--ram", ram, "");
                            }
                            return new ExecCLI(labels.getString("WRITE_RAM_CMD"), "--ram", 2, file.getAbsolutePath());
                        }
                        public void done() {
                            enableMenus();
                        }
                    };

                    worker.execute();

                }
                else {
                    output.append("\n");
                    label.setText(labels.getString("CANCEL_TEXT"));
                }
            }

            if (source.getText() == labels.getString("READ_RAM_TEXT")) {
                fc.setDialogTitle(labels.getString("SAVE_R_TO_TEXT"));
                fc.setFileFilter(new GBSaveFilter());
                int returnVal = fc.showSaveDialog(output);

                if (returnVal == JFileChooser.APPROVE_OPTION) {
                    final File file = fc.getSelectedFile();


                    // Background thread
                    org.jdesktop.swingworker.SwingWorker<Object, Void> worker = new org.jdesktop.swingworker.SwingWorker<Object, Void>() {
                        public Object doInBackground() {
                            int vram = ram;
                            if (checkSize) {
                                ExecCLI o =  new ExecCLI("--get-ram-size","",0,"");
                                vram = o.retval-11;
                            }
                            return new ExecCLI(labels.getString("READ_RAM_CMD"), "--ram", vram, file.getAbsolutePath());
                        }
                        public void done() {
                            enableMenus();
                        }
                    };

                    worker.execute();

                }
                else {
                    output.append("\n");
                    label.setText(labels.getString("CANCEL_TEXT"));
                }
            }

            if (source.getText() == labels.getString("ERASE_ROM_TEXT")) {

                // Background thread
                org.jdesktop.swingworker.SwingWorker<Object, Void> worker = new org.jdesktop.swingworker.SwingWorker<Object, Void>() {
                    public Object doInBackground() {
                        return new ExecCLI(labels.getString("ERASE_ROM_CMD"), "", 0, "");
                    }
                    public void done() {
                        enableMenus();
                    }
                };

                worker.execute();
            }

            if (source.getText() == labels.getString("ERASE_RAM_TEXT")) {

                // Background thread
                org.jdesktop.swingworker.SwingWorker<Object, Void> worker = new org.jdesktop.swingworker.SwingWorker<Object, Void>() {
                    public Object doInBackground() {
                        return new ExecCLI(labels.getString("ERASE_RAM_CMD"), "", 0, "");
                    }
                    public void done() {
                        enableMenus();
                    }
                };

                worker.execute();
            }


            if (source.getText() == labels.getString("ABOUT_TEXT")) {

                JOptionPane.showMessageDialog(frame,
                                              "JavaGBFlasher "+version+"\nDavid Pello 2008\nhttp://ladecadence.net",
                                              labels.getString("ABOUT_TEXT"),
                                              JOptionPane.INFORMATION_MESSAGE);

            }

            if (source.getText() == labels.getString("EBW_TEXT")) {

                // change state
                eraseBeforeWrite = !eraseBeforeWrite;

            }

            if (source.getText() == labels.getString("CS_TEXT")) {
                checkSize = !checkSize;
            }

            if (source.getText() == "ROM: 32 KB") {
                rom = 0;
            }

            if (source.getText() == "ROM: 64 KB") {
                rom = 1;
            }

            if (source.getText() == "ROM: 128 KB") {
                rom = 2;
            }

            if (source.getText() == "ROM: 256 KB") {
                rom = 3;
            }

            if (source.getText() == "ROM: 512 KB") {
                rom = 4;
            }

            if (source.getText() == "ROM: 1 MB") {
                rom = 5;
            }

            if (source.getText() == "ROM: 2 MB") {
                rom = 6;
            }

            if (source.getText() == "ROM: 4 MB") {
                rom = 7;
            }

            if (source.getText() == "ROM: 8 MB") {
                rom = 8;
            }

            if (source.getText() == "RAM: 2 KB") {
                ram = 0;
            }

            if (source.getText() == "RAM: 8 KB") {
                ram = 1;
            }

            if (source.getText() == "RAM: 32 KB") {
                ram = 2;
            }

            if (source.getText() == "RAM: 128 KB") {
                ram = 3;
            }

        }
        else {
            final JButton source = (JButton)(e.getSource());

	    if (source.getText() == labels.getString("STATUS_TEXT")) {

                // Background thread
                org.jdesktop.swingworker.SwingWorker<Object, Void> worker = 
		        new org.jdesktop.swingworker.SwingWorker<Object, Void>() {
                    public Object doInBackground() {
                        ExecCLI ex = new ExecCLI(labels.getString("STATUS_CMD"), "", 0, "");
                        return ex;
                    }
                    public void done() {
                        enableMenus();
                    }
                };

                worker.execute();

            }
            
	    
	    
	    if (source.getText() == labels.getString("READ_ROM_TEXT")) {
                fc.setDialogTitle(labels.getString("SAVE_F_TO_TEXT"));
                fc.setFileFilter(new GBRomFilter());
                int returnVal = fc.showSaveDialog(output);

                if (returnVal == JFileChooser.APPROVE_OPTION) {
                    final File file = fc.getSelectedFile();


                    // Background thread
                    org.jdesktop.swingworker.SwingWorker<Object, Void> worker = new org.jdesktop.swingworker.SwingWorker<Object, Void>() {

                        public Object doInBackground() {
                            int vrom = rom;
                            if (checkSize) {
                                ExecCLI o = new ExecCLI("--get-rom-size","",0,"");
                                vrom = o.retval-10;
                            }
                            return new ExecCLI(labels.getString("READ_ROM_CMD"), "--rom", vrom, file.getAbsolutePath());
                        }
                        public void done() {
                            enableMenus();
                        }
                    };

                    worker.execute();

                }
                else {
                    output.append("\n");
                    label.setText(labels.getString("CANCEL_TEXT"));
                }
            }

            if (source.getText() == labels.getString("WRITE_ROM_TEXT")) {
                fc.setDialogTitle(labels.getString("WRITE_F_FROM_TEXT"));
                fc.setFileFilter(new GBRomFilter());
                int returnVal = fc.showOpenDialog(output);

                if (returnVal == JFileChooser.APPROVE_OPTION) {
                    final File file = fc.getSelectedFile();

                    // Background thread
                    org.jdesktop.swingworker.SwingWorker<Object, Void> worker = new org.jdesktop.swingworker.SwingWorker<Object, Void>() {
                        public Object doInBackground() {
                            if (eraseBeforeWrite) {
                                Object o =  new ExecCLI(labels.getString("ERASE_ROM_CMD"), "--rom", rom, "");
                            }
                            return new ExecCLI(labels.getString("WRITE_ROM_CMD"), "--rom", rom, file.getAbsolutePath());
                        }
                        public void done() {
                            enableMenus();
                        }
                    };

                    worker.execute();

                }
                else {
                    output.append("\n");
                    label.setText(labels.getString("CANCEL_TEXT"));
                }
            }

            if (source.getText() == labels.getString("WRITE_RAM_TEXT")) {
                fc.setDialogTitle(labels.getString("WRITE_R_FROM_TEXT"));
                fc.setFileFilter(new GBSaveFilter());
                int returnVal = fc.showOpenDialog(output);

                if (returnVal == JFileChooser.APPROVE_OPTION) {
                    final File file = fc.getSelectedFile();

                    // Background thread
                    org.jdesktop.swingworker.SwingWorker<Object, Void> worker = new org.jdesktop.swingworker.SwingWorker<Object, Void>() {
                        public Object doInBackground() {
                            if (eraseBeforeWrite) {
                                Object o =  new ExecCLI(labels.getString("ERASE_RAM_CMD"), "--ram", ram, "");
                            }
                            return new ExecCLI(labels.getString("WRITE_RAM_CMD"), "--ram", 2, file.getAbsolutePath());
                        }
                        public void done() {
                            enableMenus();
                        }
                    };

                    worker.execute();

                }
                else {
                    output.append("\n");
                    label.setText(labels.getString("CANCEL_TEXT"));
                }
            }

            if (source.getText() == labels.getString("READ_RAM_TEXT")) {
                fc.setDialogTitle(labels.getString("SAVE_R_TO_TEXT"));
                fc.setFileFilter(new GBSaveFilter());
                int returnVal = fc.showSaveDialog(output);

                if (returnVal == JFileChooser.APPROVE_OPTION) {
                    final File file = fc.getSelectedFile();


                    // Background thread
                    org.jdesktop.swingworker.SwingWorker<Object, Void> worker = new org.jdesktop.swingworker.SwingWorker<Object, Void>() {
                        public Object doInBackground() {
                            int vram = ram;
                            if (checkSize) {
                                ExecCLI o =  new ExecCLI("--get-ram-size","",0,"");
                                vram = o.retval-11;
                            }
                            return new ExecCLI(labels.getString("READ_RAM_CMD"), "--ram", vram, file.getAbsolutePath());
                        }
                        public void done() {
                            enableMenus();
                        }
                    };

                    worker.execute();

                }
                else {
                    output.append("\n");
                    label.setText(labels.getString("CANCEL_TEXT"));
                }
            }

            if (source.getText() == labels.getString("ERASE_ROM_TEXT")) {

                // Background thread
                org.jdesktop.swingworker.SwingWorker<Object, Void> worker = new org.jdesktop.swingworker.SwingWorker<Object, Void>() {
                    public Object doInBackground() {
                        return new ExecCLI(labels.getString("ERASE_ROM_CMD"), "", 0, "");
                    }
                    public void done() {
                        enableMenus();
                    }
                };

                worker.execute();
            }

            if (source.getText() == labels.getString("ERASE_RAM_TEXT")) {

                // Background thread
                org.jdesktop.swingworker.SwingWorker<Object, Void> worker =
                new org.jdesktop.swingworker.SwingWorker<Object, Void>() {

                    public Object doInBackground() {
                        return new ExecCLI(labels.getString("ERASE_RAM_CMD"), "", 0, "");
                    }
                    public void done() {
                        enableMenus();
                    }
                };

                worker.execute();
            }
        }



    }

    public void itemStateChanged(ItemEvent e) {
        //...Get information from the item event...
    }


    class ExecCLI {
        int retval;

        ExecCLI(String action, String param, int val, String file)
        {
            try {

                //output.append(System.getenv("LANG"));
                java.util.List<String> command = new ArrayList<String>();

                // select windows or linux executable
                if ((System.getProperty("os.name").split(" ")[0]) == "Windows")
                    command.add("gbcf.exe");
                else
                    command.add("./gbcf");

                // params
                command.add(action);
                command.add(param);
                command.add(Integer.toString(val));
                command.add(file);

                ProcessBuilder builder = new ProcessBuilder(command);
                Map<String, String> environ = builder.environment();

                // get working dir
                builder.directory(new File(System.getProperty("user.dir")));

                // disable menus until action completes
                disableMenus();
                label.setText(labels.getString("WORKING_TEXT"));

                // start process
                final Process process = builder.start();

                // get output from process
                InputStream is = process.getInputStream();
                InputStreamReader isr = new InputStreamReader(is);
                BufferedReader br = new BufferedReader(isr);
                String line;

                // show output
                while ((line = br.readLine()) != null) {
                    if (line.length() > 0) {

                        // if it is percentage, send it to the status label
                        // if not, show text on output panel
                        if (line.charAt(line.length()-1) != '%') {
                            output.append(line + "\n");
                            scroll.getVerticalScrollBar().setValue(scroll.getVerticalScrollBar().getMaximum()+1);
                        }
                        else
                            label.setText(labels.getString("PROGRESS_TEXT") + line);
                    }
                    else
                        output.append("\n");
                }

                // finished
                output.append("\n----------------------------------------------------\n");
                label.setText(labels.getString("OK_TEXT"));
                retval = process.exitValue();

            }
            catch (Exception e) {
            }

        }
    }



    public static void main(String args[])
    {
        // thread safe
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                createGUI();
            }
        });
    }
}

