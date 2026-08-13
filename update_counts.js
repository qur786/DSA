const fs = require('fs');
const path = require('path');

// Configuration for platforms including styling for the badges
const platforms = [
    { 
        folder: 'LeetCode', 
        color: 'FFA116', 
        logo: 'LeetCode', 
        logoColor: 'black', 
        emoji: '🔥' 
    },
    { 
        folder: 'GeeksforGeeks', // Change to 'GeeksOfGeeks' if that is your exact folder name
        color: '2F8D46', 
        logo: 'GeeksforGeeks', 
        logoColor: 'white', 
        emoji: '💻' 
    },
    { 
        folder: 'CSES', 
        color: '1A2C34', 
        logo: 'codeforces', 
        logoColor: 'white', 
        emoji: '🧩' 
    }
];

let totalSolved = 0;

// Start building the HTML grid layout
let htmlContent = `<div align="center">\n  <table>\n    <tr>\n`;

platforms.forEach(platform => {
    let count = 0;
    const dirPath = path.join(__dirname, platform.folder);
    
    // Count the directories
    if (fs.existsSync(dirPath)) {
        const items = fs.readdirSync(dirPath);
        
        items.forEach(item => {
            const itemPath = path.join(dirPath, item);
            if (fs.statSync(itemPath).isDirectory()) {
                count++;
            }
        });
    }
    
    totalSolved += count;

    // Generate a visual "card" for each platform inside the table cells
    htmlContent += `      <td align="center" width="220">\n`;
    htmlContent += `        <img src="https://img.shields.io/badge/-${platform.folder}-${platform.color}?style=for-the-badge&logo=${platform.logo}&logoColor=${platform.logoColor}" alt="${platform.folder}"/><br>\n`;
    htmlContent += `        <h2>${platform.emoji} ${count}</h2>\n`;
    htmlContent += `        <b>Solved</b>\n`;
    htmlContent += `      </td>\n`;
});

// Close the platform row and add the grand total badge at the bottom
htmlContent += `    </tr>\n  </table>\n  <br>\n`;
htmlContent += `  <img src="https://img.shields.io/badge/Total_Problems_Solved-${totalSolved}-00599C?style=for-the-badge&logo=codeforces&logoColor=white" alt="Total Solved" />\n</div>`;

// Read and update the README.md
const readmePath = path.join(__dirname, 'README.md');

if (fs.existsSync(readmePath)) {
    let readmeData = fs.readFileSync(readmePath, 'utf8');
    
    const startMarker = '<!-- dsa-counts-start -->';
    const endMarker = '<!-- dsa-counts-end -->';
    
    // Swap out whatever is between the markers with the new HTML dashboard
    const regex = new RegExp(`${startMarker}[\\s\\S]*?${endMarker}`);
    readmeData = readmeData.replace(regex, `${startMarker}\n${htmlContent}\n${endMarker}`);
    
    fs.writeFileSync(readmePath, readmeData);
    console.log('✨ README.md updated successfully with beautiful stats.');
} else {
    console.error('❌ README.md not found in the root directory.');
    process.exit(1);
}
