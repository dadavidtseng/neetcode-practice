impl Solution {
    pub fn eval_rpn(tokens: Vec<String>) -> i32 {
        let mut result: i32 = tokens[0].parse().unwrap();
        let tokens_size = tokens.len();
        let mut s: Vec<i32> = Vec::new();

        if tokens_size == 1
        {
            return result;
        }

        for i in 0..tokens_size
        {
            if tokens[i] == "+"
            {
                let a = s.pop().unwrap();
                let b = s.pop().unwrap();
                result = b + a;
                s.push(result);
            }
            else if tokens[i] == "-"
            {
                let a = s.pop().unwrap();
                let b = s.pop().unwrap();
                result = b - a;
                s.push(result);
            }
            else if tokens[i] == "*"
            {
                let a = s.pop().unwrap();
                let b = s.pop().unwrap();
                result = b * a;
                s.push(result);
            }
            else if tokens[i] == "/"
            {
                let a = s.pop().unwrap();
                let b = s.pop().unwrap();
                result = b / a;
                s.push(result);
            }
            else {
                s.push(tokens[i].parse().unwrap());
            }
        }

        result
    }
}
