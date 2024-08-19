def split_file(input_file, output_prefix, chunks=10):
    try:
        with open(input_file, 'r', encoding='utf-8') as file:
            lines = file.readlines()

        # Determine the number of lines per chunk
        total_lines = len(lines)
        chunk_size = total_lines // chunks

        for i in range(chunks):
            # Determine the start and end indices for this chunk
            start_idx = i * chunk_size
            # For the last chunk, include all remaining lines
            end_idx = (i + 1) * chunk_size if i < chunks - 1 else total_lines

            # Extract the lines for this chunk
            chunk_lines = lines[start_idx:end_idx]

            # Define the output file name
            output_file = f"{output_prefix}_part_{i + 1}.txt"

            # Write the chunk to a new file
            with open(output_file, 'w', encoding='utf-8') as chunk_file:
                chunk_file.writelines(chunk_lines)

            print(f"Chunk {i + 1} saved to {output_file}")

    except FileNotFoundError:
        print(f"Error: File {input_file} not found.")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    # Define the input file and output prefix
    input_file = 'project_file_tree.txt'
    output_prefix = 'project_file_tree'

    # Split the file into 10 chunks
    split_file(input_file, output_prefix, chunks=10)