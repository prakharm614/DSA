def rotate_layer_direct(matrix, start_row, start_col, submatrix_size):
    # Handle each layer in the submatrix directly
    for layer in range(submatrix_size // 2):
        # Determine rotation direction and number of positions
        rotation_count = layer + 1
        is_odd_layer = (layer + 1) % 2 == 1
        rotation_direction = "counterclockwise" if is_odd_layer else "clockwise"
        
        # Collect the elements in the layer
        elements = []
        for i in range(start_col + layer, start_col + submatrix_size - layer):
            elements.append(matrix[start_row + layer][i])
        for i in range(start_row + layer + 1, start_row + submatrix_size - layer - 1):
            elements.append(matrix[i][start_col + submatrix_size - layer - 1])
        for i in range(start_col + submatrix_size - layer - 1, start_col + layer - 1, -1):
            elements.append(matrix[start_row + submatrix_size - layer - 1][i])
        for i in range(start_row + submatrix_size - layer - 2, start_row + layer, -1):
            elements.append(matrix[i][start_col + layer])

        # Rotate the layer
        if rotation_direction == "clockwise":
            elements = elements[-rotation_count:] + elements[:-rotation_count]
        else:  # counterclockwise
            elements = elements[rotation_count:] + elements[:rotation_count]

        # Modify the characters (shift alphabetically)
        for i in range(len(elements)):
            if is_odd_layer:
                elements[i] = chr(((ord(elements[i]) - ord('A') - 1) % 26) + ord('A'))
            else:
                elements[i] = chr(((ord(elements[i]) - ord('A') + 1) % 26) + ord('A'))

        # Place the rotated elements back into the matrix
        idx = 0
        for i in range(start_col + layer, start_col + submatrix_size - layer):
            matrix[start_row + layer][i] = elements[idx]
            idx += 1
        for i in range(start_row + layer + 1, start_row + submatrix_size - layer - 1):
            matrix[i][start_col + submatrix_size - layer - 1] = elements[idx]
            idx += 1
        for i in range(start_col + submatrix_size - layer - 1, start_col + layer - 1, -1):
            matrix[start_row + submatrix_size - layer - 1][i] = elements[idx]
            idx += 1
        for i in range(start_row + submatrix_size - layer - 2, start_row + layer, -1):
            matrix[i][start_col + layer] = elements[idx]
            idx += 1


def process_queries(matrix_size, matrix, queries):
    for query in queries:
        start_row, start_col, submatrix_size = query
        rotate_layer_direct(matrix, start_row, start_col, submatrix_size)
    
    # Convert matrix to a single string
    result = ''.join(''.join(row) for row in matrix)
    return result


# Input handling
matrix_size = int(input())  # Matrix size
matrix = [list(input().strip().split()) for _ in range(matrix_size)]  # Matrix elements
query_count = int(input().strip())  # Number of queries
queries = [tuple(map(int, input().strip().split())) for _ in range(query_count)]  # Queries

# Processing the matrix and queries
result = process_queries(matrix_size, matrix, queries)

# Output the result as a single string
print(result, end="")
