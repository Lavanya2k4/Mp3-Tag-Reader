# Mp3-Tag-Reader

1. Opened the MP3 file (sample.mp3) in binary read mode to access its content.
2. Created a temporary output file(temp.mp3) in binary write mode for saving changes.
3. Read the 10-byte ID3v2 header from the input MP3 and wrote it to the output file unchanged.
4. Looped through the first 6 metadata frames (e.g., TIT2, TPE1, etc.) of the MP3.
5. For each frame:

   * Read the 4-byte tag name (like "TIT2").
   * Read the 4-byte size of the frame and converted it from big-endian to little-endian*.
   * Read the 2-byte flag data associated with the frame.
   * Read the metadata content (e.g., song title, artist name) using the size value.
6. Checked the command-line argument (like -t, -p, -a, etc.) to determine which tag to update.
7. If the current tag matched the one to be updated:

   * Calculated the new size based on the input string.
   * Converted the size back to big-endian.
   * Wrote the tag, new size, flag, encoding byte (0x00), and new metadata to the output file.
     
8. If not matched, wrote the original tag and data unchanged to the output file.
9. After all frames, copied the remaining bytes (i.e., audio data) from the original file to the new file.
10. Closed both files, deleted the old MP3, and renamed the updated file back to the original filename.

