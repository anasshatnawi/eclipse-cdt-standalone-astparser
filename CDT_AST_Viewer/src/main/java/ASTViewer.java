package main.java;

import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.swing.JFrame;
import javax.swing.JScrollPane;
import javax.swing.JFileChooser;

import org.eclipse.cdt.core.dom.ast.IASTNode;
import org.eclipse.cdt.core.dom.ast.IASTPreprocessorIncludeStatement;
import org.eclipse.cdt.core.dom.ast.IASTTranslationUnit;
import org.eclipse.cdt.core.dom.ast.gnu.cpp.GPPLanguage;
import org.eclipse.cdt.core.parser.DefaultLogService;
import org.eclipse.cdt.core.parser.FileContent;
import org.eclipse.cdt.core.parser.IParserLogService;
import org.eclipse.cdt.core.parser.IScannerInfo;
import org.eclipse.cdt.core.parser.IncludeFileContentProvider;
import org.eclipse.cdt.core.parser.ScannerInfo;
import org.eclipse.cdt.core.parser.util.ASTPrinter;
import org.eclipse.cdt.internal.core.dom.parser.ASTNode;
import org.eclipse.cdt.internal.core.dom.parser.cpp.CPPASTCompoundStatement;
import org.eclipse.cdt.internal.core.dom.parser.cpp.CPPASTDeclarationStatement;
import org.eclipse.cdt.internal.core.dom.parser.cpp.CPPASTExpressionStatement;
import org.eclipse.cdt.internal.core.dom.parser.cpp.CPPASTIfStatement;
import org.eclipse.cdt.internal.core.dom.parser.cpp.CPPASTReturnStatement;
import org.eclipse.core.runtime.CoreException;

import treeview.JTreeTable;
import treeview.ast.ASTTreeModel;

public class ASTViewer {
	public static void main(String[] args) throws CoreException {
		new ASTViewer();
	}

	public ASTViewer() throws CoreException {
		JFrame frame = new JFrame("ASTViewer");

		JFileChooser fileChooser = new JFileChooser();

		fileChooser.setCurrentDirectory(new File("./docs"));

		int result = fileChooser.showOpenDialog(frame);
		if (result != JFileChooser.APPROVE_OPTION)
			return;

		FileContent fileContent = FileContent.createForExternalFileLocation(fileChooser.getSelectedFile().toString());

		Map definedSymbols = new HashMap();
		String[] includePaths = new String[0];
		IScannerInfo info = new ScannerInfo(definedSymbols, includePaths);
		IParserLogService log = new DefaultLogService();

		IncludeFileContentProvider emptyIncludes = IncludeFileContentProvider.getEmptyFilesProvider();

		int opts = 8;
		IASTTranslationUnit translationUnit = GPPLanguage.getDefault().getASTTranslationUnit(fileContent, info,
				emptyIncludes, null, opts, log);

		IASTPreprocessorIncludeStatement[] includes = translationUnit.getIncludeDirectives();
		for (IASTPreprocessorIncludeStatement include : includes) {
			System.out.println("include - " + include.getName());
		}

		printASTNode(translationUnit, 1);
		
//		ASTPrinter.print(translationUnit);
		JTreeTable treeTable = new JTreeTable(new ASTTreeModel(translationUnit));

		frame.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent we) {
				System.exit(0);
			}
		});
		JScrollPane scrollPane = new JScrollPane(treeTable);
		frame.getContentPane().add(scrollPane);
		frame.pack();
		frame.show();
	}

	static void printASTNode(IASTNode node, int order) {
//		if ((node instanceof CPPASTDeclarationStatement) || (node instanceof CPPASTExpressionStatement) || (node instanceof CPPASTReturnStatement) ) {
//			System.err.println(node.getClass().getName() +" : "+  node.getRawSignature());
//		}
//		
//		if ((node instanceof CPPASTIfStatement)) {
//			System.err.println(node.getClass().getName() +" : "+  node.getRawSignature());
//		}
		
		System.err.println(order + "  "+ node.getClass().getName()+" : "+  node.getRawSignature());

		
		for (IASTNode n : node.getChildren()) {
			printASTNode(n, order ++);
		}
	}
	
	static List<IASTNode> getALLElementsFromASTNode(IASTNode node) {		
		List<IASTNode> elements = new ArrayList<IASTNode>();
		elements.add(node);
		for (IASTNode n : node.getChildren()) {
			elements.addAll(getALLElementsFromASTNode(n));
		}
		return elements;
	}
}
