const allConstruct=(target,wordBank)=>{
    const dp = Array(target.length+1)
    .fill()
    .map(()=>[]);
    dp[0]=[[]];

    for (let i = 0; i <= target.length; i++) {
        
        for (let word of wordBank) {
            
            if(target.slice(i,i+word.length)===word){
                const newCombination=dp[i].map(subArray=>[...subArray,word]);
                dp[i+word.length].push(...newCombination);
            }
        }        
    }
    return dp[target.length];
}

console.log(allConstruct('purple',['purp','p','ur','le','purpl']));
console.log(allConstruct('abcdef',['ab','abc','cd','def','abcd','ef','c']));
