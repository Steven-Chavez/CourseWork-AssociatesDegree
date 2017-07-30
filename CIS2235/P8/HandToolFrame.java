package user;

import data.*;
import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Dimension;
import java.sql.SQLException;
import javax.swing.DefaultListModel;
import javax.swing.JList;
import javax.swing.JOptionPane;
import javax.swing.JTabbedPane;
import javax.swing.event.ListSelectionEvent;

/**
 * The mediator of all the classes
 * 
 * @author Steven Chavez <schavez256@yahoo.com>
 * File: HandToolFrame.java
 * ChavezP8: Database Manipulation
 * CIS 2235
 */
public class HandToolFrame extends javax.swing.JFrame
{
    private HandTool[] tool;
    private DbManager db = new DbManager();
    private UpdatePanel updatePanel = new UpdatePanel(this);
    private InsertPanel insertPanel = new InsertPanel(this);
    private DeletePanel deletePanel = new DeletePanel(this);
    private JTabbedPane tab;
    private DefaultListModel listModel;
    private JList list;
      
    public HandToolFrame()
    {
        initComponents();
        
        // create container and set layout
        Container canvas = getContentPane();
        canvas.setLayout(new BorderLayout());
        
        // create tabbed pane
        tab = new JTabbedPane();
        tab.setPreferredSize(new Dimension(466,414));
       
        tab.addTab("Update", updatePanel);
        tab.addTab("Insert", insertPanel);
        tab.addTab("Delete", deletePanel);
        
        getHandToolData();
        
        // create model for JList
        listModel = new DefaultListModel();
        
        for(int i = 0; i < tool.length; i++)
        {
            listModel.addElement(tool[i].getBrand() + ": " + 
                                 tool[i].getKind() + " " + 
                                 tool[i].getSize()); 
        }
        
        list = new JList(listModel);
        list.setPreferredSize(new Dimension(250,414));
        
         // add the components to the panel
        canvas.add(list, BorderLayout.WEST);
        canvas.add(tab, BorderLayout.CENTER);
        
        // Create and register anonymous class listeners
        list.addListSelectionListener(new ListSelectionListener());
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jMenuBar1 = new javax.swing.JMenuBar();
        jMenu1 = new javax.swing.JMenu();
        mItemExit = new javax.swing.JMenuItem();
        jMenu2 = new javax.swing.JMenu();
        jMenuItemHelp = new javax.swing.JMenuItem();
        jMenuItemAbout = new javax.swing.JMenuItem();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jMenu1.setText("File");

        mItemExit.setText("Exit");
        mItemExit.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                mItemExitActionPerformed(evt);
            }
        });
        jMenu1.add(mItemExit);

        jMenuBar1.add(jMenu1);

        jMenu2.setText("Help");

        jMenuItemHelp.setText("Help");
        jMenuItemHelp.setActionCommand("jMenuItemHelp");
        jMenuItemHelp.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItemHelpActionPerformed(evt);
            }
        });
        jMenu2.add(jMenuItemHelp);

        jMenuItemAbout.setText("About");
        jMenuItemAbout.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItemAboutActionPerformed(evt);
            }
        });
        jMenu2.add(jMenuItemAbout);

        jMenuBar1.add(jMenu2);

        setJMenuBar(jMenuBar1);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 626, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 414, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    // exit menu item exits the application
    private void mItemExitActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_mItemExitActionPerformed
        System.exit(1);
    }//GEN-LAST:event_mItemExitActionPerformed

    // About menu item gives brief explanation of program
    private void jMenuItemAboutActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItemAboutActionPerformed
        String about = "ChavezP8 is about manipulating a database using java"
                        +" and implementing CRUD functionality.";
        JOptionPane.showMessageDialog(null, about, 
                                "Help",JOptionPane.INFORMATION_MESSAGE);
        
    }//GEN-LAST:event_jMenuItemAboutActionPerformed

    // help menu item redirects user to javaDocs 
    private void jMenuItemHelpActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItemHelpActionPerformed
         JOptionPane.showMessageDialog(null, "Please refer to the javaDocs.", 
                                "About",JOptionPane.INFORMATION_MESSAGE);
    }//GEN-LAST:event_jMenuItemHelpActionPerformed

    // Obtains initial hand tool data from data base
    private void getHandToolData() 
    {
        HandTool[] temp;
        try {
            // retrieve indexes off all rows of data
            int[] indices = db.getHandToolIds();
            
            temp = new HandTool[indices.length];
            
            // retrieve each row of data by the index
            for(int i = 0; i < indices.length; i++)
            {
                temp[i] = db.getHandTool(indices[i]);
            }
            
            tool = temp;
        } 
        catch (SQLException ex) 
        {
            JOptionPane.showMessageDialog(null, "Error: " + ex.getMessage(), 
                                "SQL Error",JOptionPane.INFORMATION_MESSAGE);
        } 
    }
    
    // updates JList component
    public void updateList()
    {
        getHandToolData();
       
        listModel = new DefaultListModel();
        
        for(int i = 0; i < tool.length; i++)
        {
            listModel.addElement(tool[i].getBrand() + ": " + 
                                 tool[i].getKind() + " " + 
                                 tool[i].getSize()); 
        }
        
        list.setModel(listModel);
    }
    
    

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JMenu jMenu1;
    private javax.swing.JMenu jMenu2;
    private javax.swing.JMenuBar jMenuBar1;
    private javax.swing.JMenuItem jMenuItemAbout;
    private javax.swing.JMenuItem jMenuItemHelp;
    private javax.swing.JMenuItem mItemExit;
    // End of variables declaration//GEN-END:variables

    // updates panels with appropriate data depending on selected component 
    // on the JList
    private class ListSelectionListener implements javax.swing.event.ListSelectionListener 
    {
        @Override
        public void valueChanged(ListSelectionEvent e) 
        {
            int selectedIndex = list.getSelectedIndex();
            if(selectedIndex != -1)
            {
                updatePanel.setUpdatePanel(tool[selectedIndex]);
                deletePanel.setDeletePanel(tool[selectedIndex]);
            }   
        }
    }

    

    
}
