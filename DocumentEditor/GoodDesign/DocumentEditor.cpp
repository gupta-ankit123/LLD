#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class DocumentElement
{
public:
    virtual string render() = 0;
};

class TextElement : public DocumentElement
{
private:
    string text;

public:
    TextElement(string text)
    {
        this->text = text;
    }

    string render() override
    {
        return text;
    }
};

class ImageElement : public DocumentElement
{
private:
    string imagepath;

public:
    ImageElement(string imagepath)
    {
        this->imagepath = imagepath;
    }

    string render() override
    {
        return "[Image: " + imagepath + "]";
    }
};

class NewLineElement : public DocumentElement
{
public:
    string render() override
    {
        return "\n";
    }
};

class TabSpaceElement : public DocumentElement
{
public:
    string render() override
    {
        return "\t";
    }
};

class Document
{
private:
    vector<DocumentElement *> documentElements;

public:
    void addElement(DocumentElement *element)
    {
        documentElements.push_back(element);
    }

    string render()
    {
        string result;
        for (auto el : documentElements)
        {
            result += el->render();
        }
        return result;
    }
};

class Persistence
{
public:
    virtual void save(string data) = 0;
};

class savetoFile : public Persistence
{
    void save(string data) override
    {
        ofstream outFile("document.txt");
        if (outFile)
        {
            outFile << data;
            outFile.close();
            cout << "Document saved to document.txt" << endl;
        }
        else
        {
            cout << "Error: Unable to open file for writing." << endl;
        }
    }
};

class DBStorage : public Persistence
{
public:
    void save(string data) override
    {
        // Save to DB
    }
};

class DocumentEditor
{
private:
    Document *document;
    Persistence *storage;
    string renderedDocument;

public:
    DocumentEditor(Document *document, Persistence *storage)
    {
        this->document = document;
        this->storage = storage;
    }

    void addText(string text)
    {
        document->addElement(new TextElement(text));
    }

    void addImage(string path)
    {
        document->addElement(new ImageElement(path));
    }

    // Adds a new line to the document.
    void addNewLine()
    {
        document->addElement(new NewLineElement());
    }

    // Adds a tab space to the document.
    void addTabSpace()
    {
        document->addElement(new TabSpaceElement());
    }

    string renderDocument()
    {
        if (renderedDocument.empty())
        {
            renderedDocument = document->render();
        }
        return renderedDocument;
    }

    void saveDocument()
    {
        storage->save(renderDocument());
    }
};

int main()
{
    Document *document = new Document();
    Persistence *storage = new savetoFile();

    DocumentEditor *doceditor = new DocumentEditor(document, storage);

    doceditor->addText("Hello There, this is the start of this doc");
    doceditor->addNewLine();
    doceditor->addText("This is a real-world document editor example.");
    doceditor->addNewLine();
    doceditor->addTabSpace();
    doceditor->addText("Indented text after a tab space.");
    doceditor->addNewLine();
    doceditor->addImage("picture.jpg");

    cout << doceditor->renderDocument() << endl;

    doceditor->saveDocument();

    return 0;
}