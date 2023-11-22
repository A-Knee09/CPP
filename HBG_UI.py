from tkinter import*
from tkinter import ttk
import random
import time
import datetime
from tkinter import messagebox
import mysql.connector
conn = mysql.connector.connect(host='localhost',password='pass1234',username='root',database='mydata')
mycursor= conn.cursor()
conn.commit()
conn.close()
if conn.is_connected:
    print("True")
bg1 = "#29374d"
bg2= "#3d6466"
class Hospital:
    def __init__(self,root): #Constructor for the window
        self.root = root
        self.root.title("Hospital Management system")
        self.root.geometry("1920x1080+0+0")
        self.Fname = StringVar()
        self.Lname = StringVar()
        self.ref = StringVar()
        self.DID = StringVar()
        self.DocSp = StringVar()
        self.Admit = StringVar()
        self.Prscp = StringVar()
        self.room = StringVar()
        self.age = StringVar()
        self.address = StringVar()
        self.sex = StringVar()
        self.phone = StringVar()
        self.allergy = StringVar()
        
        
        #Title Label Frame
        Label_Title = Label(self.root,bd=20,relief="ridge",text="+ HOSPITAL MANAGEMENT SYSTEM",fg="white",bg=bg1,font=("Times New Roman",36,"bold"))
        Label_Title.pack(side=TOP,fill=X)
        
        #Patient and Invoice Frame
        Mid_Frame = Label(self.root,bd=20,relief="ridge",bg=bg1)
        Mid_Frame.place(x=0,y=120,width=1920,height=500)
        Mid_Frame_Left = LabelFrame(Mid_Frame,bd=10,relief="ridge",padx=10,font=("Times new Roman",12,"bold"),text="Patient Information")
        Mid_Frame_Left.place(x=10,y=5,width=1180,height=440)
        Mid_Frame_Right = LabelFrame(Mid_Frame,bd=10,relief="ridge",padx=10,font=("Times new Roman",12,"bold"),text="Invoice")
        Mid_Frame_Right.place(x=1200,y=5,width=660,height=440)
        
        #Buttons Frame
        Button_Frame = Label(self.root,bd=20,relief="ridge",bg=bg1)
        Button_Frame.place(x=0,y=628,width=1920,height=105)

        #Details Frame
        Details_Frame = Label(self.root,bd=20,relief="ridge",bg=bg1)
        Details_Frame.place(x=0,y=744,width=1920,height=300)
        
        
        #Mid_Frame_Left Buttons
        lb_Patient_FName = Label(Mid_Frame_Left,text="Patient First Name",font=("Times new Roman",12,"bold"),padx=6,pady=11).grid(row=0,column=0,sticky=W)
        Patient_FName_txt = Entry(Mid_Frame_Left,font=("Times new Roman",12,"bold"),textvariable = self.Fname,width=35).grid(row=0,column=1)

        lb_Patient_FName = Label(Mid_Frame_Left,text="Patient Last Name",font=("Times new Roman",12,"bold"),padx=6,pady=11).grid(row=1,column=0,sticky=W)
        Patient_FName_txt = Entry(Mid_Frame_Left,font=("Times new Roman",12,"bold"),textvariable = self.Lname,width=35).grid(row=1,column=1)
        
        lb_Patient_Ref = Label(Mid_Frame_Left,text="Reference Number",font=("Times new Roman",12,"bold"),padx=6,pady=11).grid(row=2,column=0,sticky=W)
        Patient_Ref_txt = Entry(Mid_Frame_Left,font=("Times new Roman",12,"bold"),textvariable = self.ref,width=35).grid(row=2,column=1,padx=10)

        lb_Doctor_ID = Label(Mid_Frame_Left,text="Doctor ID",font=("Times new Roman",12,"bold"),padx=6,pady=11).grid(row=3,column=0,sticky=W)
        Doctor_ID_txt = Entry(Mid_Frame_Left,font=("Times new Roman",12,"bold"),textvariable = self.DID,width=35).grid(row=3,column=1)
        
        lb_Doctor_Sepciality = Label(Mid_Frame_Left,text="Specialist",font=("Times new Roman",12,"bold"),padx=6,pady=11).grid(row=4,column=0,sticky=W)
        comSpeciality = ttk.Combobox(Mid_Frame_Left,state="readonly",font=("Times new Roman",12,"bold"),width=33,textvariable =self.DocSp)
        comSpeciality['values']=("...","Cardiologist","Oncologist","Neurologist","Gynecologist","Orhtopedic Surgeon","Urologist","Endocrinologist")
        comSpeciality.current(0)
        comSpeciality.grid(row=4,column=1)
        
        
        lb_Admit = Label(Mid_Frame_Left,text="Days Admitted",font=("Times new Roman",12,"bold"),padx=6,pady=11).grid(row=5,column=0,sticky=W)
        Admit_txt = Entry(Mid_Frame_Left,font=("Times new Roman",12,"bold"),width=35,textvariable =self.Admit).grid(row=5,column=1,padx=10)

        lb_Prescription = Label(Mid_Frame_Left,text="Prescription",font=("Times new Roman",12,"bold"),padx=6,pady=11).grid(row=6,column=0,sticky=W)
        Prescription_txt = Entry(Mid_Frame_Left,font=("Times new Roman",12,"bold"),textvariable =self.Prscp,width=35).grid(row=6,column=1,padx=10)

        lb_Room = Label(Mid_Frame_Left,text="Room",font=("Times new Roman",12,"bold"),padx=6,pady=11).grid(row=7,column=0,sticky=W)
        comRoom = ttk.Combobox(Mid_Frame_Left,state="readonly",font=("Times new Roman",12,"bold"),width=33,textvariable =self.room)
        comRoom['values']=("None","InPatient Room","Semi Private","Private","Deluxe Room")
        comRoom.current(0)
        comRoom.grid(row=7,column=1)
        
        lb_Patient_Age = Label(Mid_Frame_Left,text="Patient Age",font=("Times new Roman",12,"bold"),padx=16).grid(row=0,column=2,sticky=W)
        Age_txt = Entry(Mid_Frame_Left,font=("Times new Roman",12,"bold"),width=35,textvariable =self.age).grid(row=0,column=3,padx=10)
        
        lb_Patient_Add = Label(Mid_Frame_Left,text="Patient Address",font=("Times new Roman",12,"bold"),padx=16).grid(row=1,column=2,sticky=W)
        Add_txt = Entry(Mid_Frame_Left,font=("Times new Roman",12,"bold"),width=35,textvariable =self.address).grid(row=1,column=3,padx=10)

        lb_Patient_Gender = Label(Mid_Frame_Left,text="Gender",font=("Times new Roman",12,"bold"),padx=16).grid(row=2,column=2,sticky=W)
        comGender = ttk.Combobox(Mid_Frame_Left,state="readonly",font=("Times new Roman",12,"bold"),width=33,textvariable =self.sex)
        comGender['values']=("...","Male","Female","Other")
        comGender.current(0)
        comGender.grid(row=2,column=3)

        lb_Patient_Phone = Label(Mid_Frame_Left,text="Phone Number",font=("Times new Roman",12,"bold"),padx=16).grid(row=3,column=2,sticky=W)
        Phone_txt = Entry(Mid_Frame_Left,font=("Times new Roman",12,"bold"),width=35,textvariable =self.phone).grid(row=3,column=3,padx=10)

        lb_Patient_Allergy = Label(Mid_Frame_Left,text="Prior Allergy(Y/N)",font=("Times new Roman",12,"bold"),padx=16).grid(row=4,column=2,sticky=W)
        comAllergy = ttk.Combobox(Mid_Frame_Left,state="readonly",font=("Times new Roman",12,"bold"),width=33,textvariable =self.allergy)
        comAllergy['values']=("...","Yes","No")
        comAllergy.current(0)
        comAllergy.grid(row=4,column=3)
        
        #Invoice Page
        self.Invoice_Txt = Text(Mid_Frame_Right,font=("Times new Roman",12,"bold"),width=60,height=16,padx=6,pady=11)
        self.Invoice_Txt.grid(row=0,column=0)
        
        
        #Buttons
        Bill_Gen_bt = Button(Button_Frame,command=self.Invoice_Data,text="Generate Bill",font=("Times new Roman",12,"bold"),width=23,height=1,padx=14,pady=13,bg=bg2,fg="white").grid(row=0,column=0)
        Bill_Data_bt = Button(Button_Frame,command=self.Bill_Save,text="Save Bill",font=("Times new Roman",12,"bold"),width=23,height=1,padx=14,pady=13,bg=bg2,fg="white").grid(row=0,column=1) 
        Bill_Update_bt = Button(Button_Frame,command=self.Update,text="Update",font=("Times new Roman",12,"bold"),width=23,height=1,padx=14,pady=13,bg=bg2,fg="white").grid(row=0,column=2) 
        Bill_Delete_bt = Button(Button_Frame,command=self.delete,text="Delete",font=("Times new Roman",12,"bold"),width=23,height=1,padx=14,pady=13,bg=bg2,fg="white").grid(row=0,column=3) 
        Bill_Reset_bt = Button(Button_Frame,command=self.clear,text="Reset",font=("Times new Roman",12,"bold"),width=23,height=1,padx=14,pady=13,bg=bg2,fg="white").grid(row=0,column=4) 
        Bill_Exit_bt = Button(Button_Frame,command=self.end,text="Exit",font=("Times new Roman",12,"bold"),width=23,height=1,padx=14,pady=13,bg=bg2,fg="white").grid(row=0,column=5) 
        
        
        #Bill Table
        scroll_x = ttk.Scrollbar(Details_Frame,orient=HORIZONTAL)
        scroll_y = ttk.Scrollbar(Details_Frame,orient=VERTICAL)
        self.Hospital_Table = ttk.Treeview(Details_Frame,column=("Fname","Lname","ref","DID","DocSp","Admit","Prscp","room","age","address","sex","phone","allergy"),xscrollcommand=scroll_x.set,yscrollcommand=scroll_y.set)
        scroll_x.pack(side=BOTTOM,fill=X)
        scroll_y.pack(side=RIGHT,fill=Y)  
        
        scroll_x=ttk.Scrollbar(command=self.Hospital_Table.xview)
        scroll_y=ttk.Scrollbar(command=self.Hospital_Table.yview)
        self.Hospital_Table.heading("Fname",text="First Name") 
        self.Hospital_Table.heading("Lname",text="Last Name") 
        self.Hospital_Table.heading("ref",text="Ref Number") 
        self.Hospital_Table.heading("DID",text="Doctor ID") 
        self.Hospital_Table.heading("DocSp",text="Specialist") 
        self.Hospital_Table.heading("Admit",text="Days Admitted") 
        self.Hospital_Table.heading("Prscp",text="Med Prescribed") 
        self.Hospital_Table.heading("room",text="Room type") 
        self.Hospital_Table.heading("age",text="Age") 
        self.Hospital_Table.heading("address",text="Address") 
        self.Hospital_Table.heading("sex",text="Sex") 
        self.Hospital_Table.heading("phone",text="Phone No.") 
        self.Hospital_Table.heading("allergy",text="Allergy") 
        self.Hospital_Table["show"]="headings"
        self.Hospital_Table.pack(fill=BOTH,expand=1)
        
        self.Hospital_Table.column("Fname",width=100)
        self.Hospital_Table.column("Lname",width=100)
        self.Hospital_Table.column("ref",width=100)
        self.Hospital_Table.column("DID",width=100)
        self.Hospital_Table.column("DocSp",width=100)
        self.Hospital_Table.column("Admit",width=100)
        self.Hospital_Table.column("Prscp",width=100)
        self.Hospital_Table.column("room",width=100)
        self.Hospital_Table.column("age",width=100)
        self.Hospital_Table.column("address",width=100)
        self.Hospital_Table.column("sex",width=100)
        self.Hospital_Table.column("phone",width=100)
        self.Hospital_Table.column("allergy",width=100)
        self.Hospital_Table.pack(fill=BOTH,expand=1)
        #self.Hospital_Table.bind("<ButtonRelease-1>",self.get_cursor)
        self.fetch_data()

        
        #================Functionality================
    def fetch_data(self):
                conn = mysql.connector.connect(host="localhost",username="root",password="pass1234",database="MyData")
                mycursor = conn.cursor()
                mycursor.execute("select * from hospital")
                rows=mycursor.fetchall()                    
                if len(rows)!=0:
                    self.hospital_table.delete(*self.hospital_table.get_children())
                    for i in rows:
                        self.hospital_table.insert("",END,values=i)
                    conn.commit()
                conn.close()  
                               
    def Bill_Save(self):
            if self.ref.get()=="" or self.DID.get()=="":
                messagebox.showerror("Error","Field cannot be left empty!")
            else:
                conn = mysql.connector.connect(host="localhost",username="root",password="pass1234",database="MyData")
                mycursor = conn.cursor()
                mycursor.execute("Insert into Hospital values(%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,)",(
                                                                                                        self.Fname.get(),
                                                                                                        self.Lname.get(),
                                                                                                        self.ref.get(),
                                                                                                        self.DID.get(),
                                                                                                        self.DocSp.get(),
                                                                                                        self.Admit.get(),
                                                                                                        self.Prscp.get(),
                                                                                                        self.room.get(),
                                                                                                        self.age.get(),
                                                                                                        self.address.get(),
                                                                                                        self.sex.get(),
                                                                                                        self.phone.get(),
                                                                                                        self.allergy.get()
                                                                                                        ))
                conn.commit()
                self.fetch_data()
                conn.close()                 
                messagebox.showinfo("Success","Data has been succesfully added.",parent=self.root)                  
                              
    def Update(self):
        conn = mysql.connector.connect(host="localhost",username="root",password="pass1234",database="MyData")
        mycursor = conn.cursor()
        mycursor.execute("Update hospital set Fname=%s,Lname=%s,ref=%s,DID=%s,DocSp=%s,Admit=%s,Prscp=%s,room=%s,age=%s,address=%s,sex=%s,phone=%s,allergy=%s where ref=%s",(self.Fname.get(),
                       self.Lname.get(),
                       self.ref.get(),
                       self.DID.get(),
                       self.DocSp.get(),
                       self.Admit.get(),
                       self.Prscp.get(),
                       self.room.get(),
                       self.age.get(),
                       self.address.get(),
                       self.sex.get(),
                       self.phone.get(),
                       self.allergy.get()))


    def calculate_doctor_fee(self, doctor_specialist):
        fee = 0  # Initialize fee to 0

    # Check the specialist type and set the fee accordingly
        if doctor_specialist.lower() in ["cardiologist", "neurologist", "endocrinologist"]:
            fee = 2000
        elif doctor_specialist.lower() in ["oncologist", "gynecologist", "orthopedic surgeon", "urologist"]:
         fee = 1100

        return fee
    
    def calculate_Room_fee(self, room, days):
        rfee = 0  
        rdays = int(self.Admit.get()) if self.Admit.get() else 0  # Convert admitted days to an integer if it's not an empty string

        if room.lower() in ["inpatient", "semi private", "none"]:
            rfee = 1000 * rdays
        elif room.lower() in ["private", "deluxe"]:
            rfee = 2500 * rdays

        return rfee

        return rfee
    def calculate_med_fee(self,med):
        mfee = 0
        if self.Prscp.get():
            mfee =500
        return mfee
        
   

    def Invoice_Data(self):
        self.Invoice_Txt.insert(END,"First Name:\t\t\t"+self.Fname.get()+"\n")                 
        self.Invoice_Txt.insert(END,"Last Name:\t\t\t"+self.Lname.get()+"\n")                 
        self.Invoice_Txt.insert(END,"Reference Number:\t\t\t"+self.ref.get()+"\n")                 
        self.Invoice_Txt.insert(END,"Doctor ID:\t\t\t"+self.DID.get()+"\n")                 
        self.Invoice_Txt.insert(END,"Specialist:\t\t\t"+self.DocSp.get()+"\n")                 
        self.Invoice_Txt.insert(END,"Days admitted:\t\t\t"+self.Admit.get()+"\n")                 
        self.Invoice_Txt.insert(END,"Prescribed Medicine:\t\t\t"+self.Prscp.get()+"\n")                 
        self.Invoice_Txt.insert(END,"Room Type:\t\t\t"+self.room.get()+"\n")                 
        self.Invoice_Txt.insert(END,"Patient Age:\t\t\t"+self.age.get()+"\n")                 
        self.Invoice_Txt.insert(END,"Address:\t\t\t"+self.address.get()+"\n")                 
        self.Invoice_Txt.insert(END,"Gender:\t\t\t"+self.sex.get()+"\n")                 
        self.Invoice_Txt.insert(END,"Phone Number:\t\t\t"+self.phone.get()+"\n")                 
        self.Invoice_Txt.insert(END,"Any history to allergy:\t\t\t"+self.allergy.get()+"\n")                 
    
        doctor_fee = self.calculate_doctor_fee(self.DocSp.get())
        room_fee = self.calculate_Room_fee(self.room.get(), self.Admit.get())
        med_fee = self.calculate_med_fee(self.Prscp.get())
        total_bill = doctor_fee + room_fee + med_fee
        bill_amount = str(total_bill)
        self.Invoice_Txt.insert(END, "Bill Generated:\t\t\t" + bill_amount + "\n")

    def delete(self):
        conn = mysql.connector.connect(host="localhost",username="root",password="pass1234",database="MyData")
        mycursor = conn.cursor()
        query = "delete from hospital where ref = %s"
        value = (self.ref.get(),)               
        mycursor.execute(query,value)
        conn.commit()
        conn.close()
        self.fetch_data()
        messagebox.showinfo("Delete","Record Has been deleted")
    
    def clear(self):
        self.Fname.set(""),
        self.Lname.set(""),
        self.ref.set(""),
        self.DID.set(""),
        self.DocSp.set(""),
        self.Admit.set(""),
        self.Prscp.get(),
        self.room.set(""),
        self.age.set(""),
        self.address.set(""),
        self.sex.set(""),
        self.phone.set(""),
        self.allergy.set("")
        self.Invoice_Data.delete(1.0, END)

    def end(self):
        end = messagebox.askyesno("Hospital Management System","Are you sure you want to exit the program")
        if end>0:
            root.destroy()
            return
        
            
    
    
    
    
       
root = Tk()
obj = Hospital(root)
root.mainloop()