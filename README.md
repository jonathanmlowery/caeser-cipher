# caeser-cipher

## Usage
```sh
./caesar-cipher [-E|-e|-D|-d] [message_or_input_file] [-o output_file] [-k key]
```
This program encrypts or decrypts text using the **Caesar cipher**. You can specify options via command-line flags or be prompted for missing values.

---

## Command-Line Options
| Flag       | Argument         | Description |
|------------|------------------|-------------|
| `-E`       | `[message]`      | **Encrypt** mode. If followed by text, encrypts it directly. |
| `-D`       | `[message]`      | **Decrypt** mode. If followed by text, decrypts it directly. |
| `-e`       | `[input_file]`   | **Encrypt** mode. If followed by a file path, encrypts the file’s contents. |
| `-d`       | `[input_file]`   | **Decrypt** mode. If followed by a file path, decrypts the file’s contents. |
| `-o`       | `output_file`    | Specifies an **output file** to save the result. |
| `-k`       | `key (integer)`  | Specifies the **shift key** (between 1-25) for the cipher. |

---

## Examples
### **Encrypting a message directly:**
```sh
./caesar-cipher -E "hello world" -k 3
```
🔹 **Encrypts** `"hello world"` with shift **3**, outputs to **stdout**.

### **Decrypting from a file and saving output:**
```sh
./caesar-cipher -d input.txt -k 5 -o decrypted.txt
```
🔹 **Reads** `input.txt`, **decrypts** using key **5**, and **writes** to `decrypted.txt`.

### **Encrypting interactively (prompt for missing values):**
```sh
./caesar-cipher -e -o encrypted.txt
```
🔹 **Prompts** for the input file and shift key.

### **Incorrect Usage (Missing Key Argument):**
```sh
./caesar-cipher -E "hello" -k
```
The program will **detect the missing key** and **prompt for it**.

---

## Behavior
- If a required flag (`-k` or input text) is missing, **the user will be prompted**.  
- `-E` and `-D` (uppercase) **can take a message directly**.  
- `-e` and `-d` (lowercase) **can take a file path**.  
- `-o` and `-k` **must** be followed by an argument.  
