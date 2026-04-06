import msoffcrypto
import sys

def decrypt_excel(input_path, password, output_path):
    try:
        with open(input_path, "rb") as f:
            file = msoffcrypto.OfficeFile(f)
            file.load_key(password=password)
            with open(output_path, "wb") as decrypted:
                file.decrypt(decrypted)
        return 0
    except Exception as e:
        return 1


if __name__ == "__main__":
    if len(sys.argv) == 4:
        sys.exit(decrypt_excel(sys.argv[1], sys.argv[2], sys.argv[3]))