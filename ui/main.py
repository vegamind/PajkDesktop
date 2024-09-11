import os
import subprocess
from tkinter import Tk, Label, Entry, Button, StringVar, messagebox

def run_pajk_command():
    file_path = file_path_var.get()
    
    # Check if the file path exists
    if os.path.exists(file_path):
        try:
            # Construct the command to run
            command = f'./pajk "{file_path}"'
            
            # Run the command
            result = subprocess.run(command, shell=True, capture_output=True, text=True)
            
            # Display the result or any errors
            if result.returncode == 0:
                messagebox.showinfo("Success", f"Command executed successfully!\nOutput: {result.stdout}")
            else:
                messagebox.showerror("Error", f"Command failed with error:\n{result.stderr}")
        except Exception as e:
            messagebox.showerror("Exception", f"An error occurred: {str(e)}")
    else:
        messagebox.showerror("Invalid Path", "The file path does not exist.")

# Create the main window
root = Tk()
root.title("File Path Submission")

# StringVar to hold the file path input
file_path_var = StringVar()

# Create and place widgets
Label(root, text="Enter File Path:").pack(pady=10)
Entry(root, textvariable=file_path_var, width=50).pack(padx=20)

Button(root, text="Submit", command=run_pajk_command).pack(pady=20)

# Start the Tkinter event loop
root.mainloop()
