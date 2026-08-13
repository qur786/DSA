const fs = require('fs');
const path = require('path');

// Folder names must match your repository exactly
const platforms = ['LeetCode', 'GeeksforGeeks', 'CSES'];
let totalSolved = 0;

let markdownContent = '| Platform | Solved Count |\n| --- | --- |\n';

platforms.forEach(platform => {
    let count = 0;
    const dirPath = path.join(__dirname, platform);
    
    if (fs.existsSync(dirPath)) {
        // Read the directory contents
        const items = fs.readdirSync(dirPath);
        
        items.forEach(item => {
            const itemPath = path.join(dirPath, item);
            // Increment only if the item is a directory (ignoring loose files)
            if (fs.statSync(itemPath).isDirectory()) {
                count++;
            }
        });
    }
    
    markdownContent += `| ${platform} | ${count} |\n`;
    totalSolved += count;
});

markdownContent += `| **Total** | **${totalSolved}** |\n`;

// Inject the table into README.md
const readmePath = path.join(__dirname, 'README.md');

if (fs.existsSync(readmePath)) {
    let readmeData = fs.readFileSync(readmePath, 'utf8');
    
    const startMarker = '<!-- dsa-counts-start -->';
    const endMarker = '<!-- dsa-counts-end -->';
    
    // Replace existing content between the markers
    const regex = new RegExp(`${startMarker}[\\s\\S]*?${endMarker}`);
    readmeData = readmeData.replace(regex, `${startMarker}\n${markdownContent}\n${endMarker}`);
    
    fs.writeFileSync(readmePath, readmeData);
    console.log('README.md updated successfully.');
} else {
    console.error('README.md not found in the root directory.');
    process.exit(1);
}
